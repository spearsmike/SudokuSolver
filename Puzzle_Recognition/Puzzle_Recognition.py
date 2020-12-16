import cv2
import pytesseract
import sys
import numpy as np
# Global Variables #
custom_config = r'--psm 13 -c tessedit_char_whitelist=0123456789'
result_filename = "unsolved_puzzle.csv"
status_filename = "status.txt"


def clipToROI(img, roi):
    img_h, img_w = img.shape
    roi_length = int(min(img.shape[0:2]) * roi)
    roi_y = (img_h // 2) - (roi_length // 2)
    roi_x = (img_w // 2) - (roi_length // 2)
    return img[roi_y: roi_y + roi_length, roi_x: roi_x + roi_length]


def is_floatstring(s):
    try:
        val = float(s)
        if val >= 0 and val <= 1:
            return True

        return False
    except ValueError:
        return False


def findPuzzleBoundary(img):
    # Image Processing #
    blur_img = cv2.GaussianBlur(img.copy(), (3, 3), 0)  # remove noise from image
    thresh = cv2.threshold(blur_img.copy(), 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]  # keep only dark lines
    # Aproximating location of lines #
    contours, hierarchy = cv2.findContours(thresh, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)
    # iterate each contour in contours array #
    for contour in sorted_contours:
        peri = cv2.arcLength(contour, True)  # find perimeter of contour
        approx = cv2.approxPolyDP(contour, 0.04 * peri, True)  # Douglas-Puecker Algorithm
        (x, y, w, h) = cv2.boundingRect(approx)
        if (
            len(approx) == 4 and
            w > thresh.shape[1] * 0.50 and
            h > thresh.shape[0] * 0.50
        ):
            return approx
    return []


def checkPuzzle(img):
    img_h, img_w = img.shape
    if img_h < 300 or img_w < 300:
        writeStatus("error: Image or ROI to Small")
        sys.exit("Error: Image too small")

    return img


def warpPuzzle(img, contour):
    img_h, img_w = img.shape
    pt1 = contour[0][0]
    pt2 = contour[1][0]
    pt3 = contour[2][0]
    pt4 = contour[3][0]
    if (
        pt1[0] < img_w//2 and pt1[1] < img_h//2 and
        pt2[0] < img_w//2 and pt2[1] > img_h//2 and
        pt3[0] > img_w//2 and pt3[1] > img_h//2 and
        pt4[0] > img_w//2 and pt4[1] < img_h//2
    ):
        top_left_corner = pt1
        bottom_left_corner = pt2
        bottom_right_corner = pt3
        top_right_corner = pt4
    elif (
        pt2[0] < img_w//2 and pt2[1] < img_h//2 and
        pt3[0] < img_w//2 and pt3[1] > img_h//2 and
        pt4[0] > img_w//2 and pt4[1] > img_h//2 and
        pt1[0] > img_w//2 and pt1[1] < img_h//2
    ):
        top_left_corner = pt2
        bottom_left_corner = pt3
        bottom_right_corner = pt4
        top_right_corner = pt1
    src_pts = np.float32([top_left_corner, bottom_left_corner, bottom_right_corner, top_right_corner])
    dst_pts = np.float32([[0, 0], [0, img_h], [img_w, img_h], [img_w, 0]])
    M = cv2.getPerspectiveTransform(src_pts, dst_pts)
    return cv2.warpPerspective(img.copy(), M, (img_w, img_h))


def readCells(img):
    # image processing #
    img = cv2.medianBlur(img, 3)
    img = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)[1]
    img = cv2.resize(img, (2000, 2000), interpolation=cv2.INTER_CUBIC)
    img_h, img_w = img.shape
    cell_height = (img_h // 9)
    cell_width = (img_w // 9)

    cells = [['0' for i in range(9)] for j in range(9)]
    for i in range(9):
        for j in range(9):
            cell_y = cell_height * i
            cell_x = cell_width * j
            cell_img = img[cell_y+30:cell_y + cell_height-30, cell_x+30:cell_x+cell_width-30]
            cell_char = pytesseract.image_to_string(cell_img, config=custom_config)[0]
            if ord(cell_char) == 12:
                cells[i][j] = '0'
            else:
                cells[i][j] = cell_char

    return cells


def writeResultToFile(cells):
    try:
        f = open(result_filename, "w")
    except IOError:
        sys.exit("error: could not open result file")
    for i in range(9):
        for j in range(9):
            f.write(cells[i][j])
            if j < 8:
                f.write(',')
        f.write('\n')
    f.close()


def writeStatus(status):
    try:
        f = open(status_filename, "w")
    except IOError:
        sys.exit("error: could not open status file")
    f.write(status)
    f.close()


def main():
    # local variables #
    roi = float(0.7)

    # check cmdline arguments #
    if len(sys.argv) > 3 or len(sys.argv) < 2:
        sys.exit("Error: incorrect number of arguments.\nFor help use -help")
    if (sys.argv[1] == "-h" or sys.argv[1] == "-help"):
        sys.exit("$ python Puzzle_Recognition image_name.jpg roi")

    file_type = sys.argv[1].split('.')[-1]
    if file_type != "png" and file_type != "jpg":
        sys.exit("Error: Incorrect file type. .jpg & .png only")
    if len(sys.argv) == 3:
        if not is_floatstring(sys.argv[2]):
            sys.exit("Error: argument 2 must be a decimal number between 0 and 1")
        else:
            roi = float(sys.argv[2])

    writeStatus("in-progress")

    # Load Image #
    gray_img = cv2.imread(sys.argv[1], flags=cv2.IMREAD_GRAYSCALE)  # grayscale image
    if gray_img is None:
        writeStatus("error: unable to open image")
        sys.exit("error: unable to open image")

    # clip images to roi #
    roi_img = clipToROI(gray_img, roi)

    # Find Puzzle #
    boundary = findPuzzleBoundary(roi_img)
    if len(boundary) == 0:
        writeStatus("error: No puzzle found")
        sys.exit("Error: No puzzle found")

    # Perspective Transformation #
    puzzle_img = warpPuzzle(roi_img, boundary)

    # check if valid puzzle #
    valid_img = checkPuzzle(puzzle_img)

    # Read cells of puzzle #
    puzzle_cell_numbers = readCells(valid_img)

    # write puzzle to csv file #
    writeResultToFile(puzzle_cell_numbers)
    writeStatus("success")
    return


if __name__ == "__main__":
    main()
