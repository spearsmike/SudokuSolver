import cv2
import pytesseract
import sys
import numpy as np

custom_config = r'--psm 10 -c tessedit_char_whitelist=0123456789'
result_filename = "unsolved_puzzle.csv"
status_filename = "status.txt"


def clipToROI(img, roi):
    img_h, img_w = img.shape
    # roi_y = img_h//2 - roi//2
    # roi_x = img_w//2 - roi//2
    roi_length = int(min(img.shape[0:2]) * roi)
    roi_y = (img_h // 2) - (roi_length // 2)
    roi_x = (img_w // 2) - (roi_length // 2)
    # roi_y = int(img_h * verti_roi)  # height of image * percentage of verti_roi
    # roi_x = int(img_w * horizi_roi)  # width of image * percentage of horizi_roi
    # roi_h = img_h - (2 * roi_y)
    # roi_w = img_w - (2 * roi_x)
    # roi = (roi_h + roi_w) // 2

    return img[roi_y: roi_y + roi_length, roi_x: roi_x + roi_length]


def findPuzzleBoundary(thresh):
    # Aproximating location of lines #
    contours, hierarchy = cv2.findContours(thresh, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)
    for contour in sorted_contours:  # iterate each contour in contours array
        peri = cv2.arcLength(contour, True)  # find perimeter of contour
        approx = cv2.approxPolyDP(contour, 0.04 * peri, True)  # Douglas-Puecker Algorithm
        (x, y, w, h) = cv2.boundingRect(approx)
        # ar = w / float(h)
        if (
            len(approx) == 4 and
            w > thresh.shape[1] * 0.60 and
            h > thresh.shape[0] * 0.60
        ):
            return approx

            # if (ar >= 0.95) and (w > thresh.shape[1] * 0.80) and (h > thresh.shape[0] * 0.80):
            #    return approx
    return []


def warpPuzzle(img, contour):
    img_h, img_w = img.shape
    pts1 = np.float32([contour[0][0], contour[1][0], contour[2][0], contour[3][0]])
    pts2 = np.float32([[0, 0], [0, img_h], [img_w, img_h], [img_w, 0]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    return cv2.warpPerspective(img.copy(), M, (img_w, img_h))


def is_floatstring(s):
    try:
        val = float(s)
        if val >= 0 and val <= 1:
            return True

        return False
    except ValueError:
        return False


def readCells(img):
    img_h, img_w = img.shape
    cell_height = (img_h // 9)
    cell_width = (img_w // 9)

    cells = [['0' for i in range(9)] for j in range(9)]
    for i in range(9):
        for j in range(9):
            cell_y = cell_height * i
            cell_x = cell_width * j
            cell_img = img[cell_y+5:cell_y + cell_height-5, cell_x+5:cell_x+cell_width-5]

            # cv2.imshow("cell", cell_img)
            # cv2.waitKey(500)
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

    # cmdline arguments #
    if sys.argv[1] == "-h" or sys.argv[1] == "-help":
        sys.exit("$ python Puzzle_Recognition image_name.jpg roi")

    if len(sys.argv) != 3:
        sys.exit("Error: incorrect number of arguments.\nFor help use -help")

    file_type = sys.argv[1].split('.')[-1]
    if file_type != "png" and file_type != "jpg":
        sys.exit("Error: Incorrect file type. .jpg & .png only")

    if not is_floatstring(sys.argv[2]):
        sys.exit("Error: argument 2 must be a decimal number between 0 and 1")

    # if not is_floatstring(sys.argv[3]):
    #    sys.exit("Error: argument 3 must be a decimal number between 0 and .5")

    writeStatus("in-progress")

    # Load Image #
    gray_img = cv2.imread(sys.argv[1], flags=cv2.IMREAD_GRAYSCALE)  # grayscale image

    # clip images to roi #
    roi_img = clipToROI(gray_img, float(sys.argv[2]))

    # Image Processing #
    blur = cv2.GaussianBlur(roi_img.copy(), (3, 3), 0)  # remove noise from image

    thresh = cv2.threshold(blur.copy(), 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]  # keep only dark lines

    # Find Puzzle #
    boundary = findPuzzleBoundary(thresh)
    if len(boundary) == 0:
        writeStatus("error: No puzzle found")
        sys.exit("Error: No puzzle found")

    # dewarp puzzle #
    puzzle_img = warpPuzzle(blur, boundary)

    # sobel_img = cv2.Sobel(puzzle_img, cv2.CV_16S, 1, 0)
    # thresh = cv2.threshold(puzzle_img, 0, 255, cv2.THRESH_OTSU)[1]
    # erode_img = cv2.erode(thresh, (5, 5))
    # cv2.imshow("sobel", sobel_img)
    # Read cells of puzzle #
    puzzle_cell_numbers = readCells(puzzle_img)

    # write puzzle to csv file #
    writeResultToFile(puzzle_cell_numbers)
    writeStatus("success")
    # final_img = cv2.drawContours(roi_img, [boundary], -1, (255, 255, 255), 3)  # draw the puzzle border
    # testing purposes
    # cv2.namedWindow("squares", flags=(cv2.WINDOW_NORMAL + cv2.WINDOW_KEEPRATIO))
    # cv2.resizeWindow("squares", 500, 500)
    # cv2.imshow("squares", final_img)  # open image in a window
    # cv2.namedWindow("puzzle_img", flags=(cv2.WINDOW_NORMAL + cv2.WINDOW_KEEPRATIO))
    # cv2.resizeWindow("puzzle_img", 500, 500)
    # cv2.imshow("puzzle_img", puzzle_img)  # open image in a window
    # cv2.waitKey(0)  # wait for a key press
    # cv2.destroyAllWindows()  # close window
    return


if __name__ == "__main__":
    main()
