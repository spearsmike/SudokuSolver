import cv2
import pytesseract
import sys
custom_config = r'--psm 10 -c tessedit_char_whitelist=0123456789'
result_filename = "unsolved_puzzle.csv"


def findPuzzleBoundary(thresh):
    # Aproximating location of lines #
    contours, h = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for contour in contours:  # iterate each contour in contours array
        peri = cv2.arcLength(contour, True)  # find perimeter of contour
        approx = cv2.approxPolyDP(contour, 0.04 * peri, True)  # Douglas-Puecker Algorithm
        if len(approx) == 4:
            (x, y, w, h) = cv2.boundingRect(approx)
            ar = w / float(h)
            if (ar >= 0.95) and (w > thresh.shape[1] * 0.80) and (h > thresh.shape[0] * 0.80):
                return approx
    return []


def is_floatstring(s):
    try:
        val = float(s)
        if val >= 0 and val <= 1:
            return True

        return False
    except ValueError:
        return False


def readCells(img, boundary):
    (x, y, w, h) = cv2.boundingRect(boundary)
    cell_width = w // 9
    cell_height = h // 9
    cells = [['\0' for i in range(9)] for j in range(9)]
    for i in range(9):
        for j in range(9):
            cell_y = y + cell_height * i
            cell_x = x + cell_width * j
            cell_img = img[cell_y+5:cell_y + cell_height-5, cell_x+5:cell_x+cell_width-5]
            cell_char = pytesseract.image_to_string(cell_img, config=custom_config)[0]
            if ord(cell_char) == 12:
                cells[i][j] = 'X'
            else:
                cells[i][j] = cell_char

    return cells


def writeResultToFile(cells):
    f = open(result_filename, "w")
    for i in range(9):
        for j in range(9):
            f.write(cells[i][j])
            if j < 8:
                f.write(', ')
        f.write('\n')
    f.close()


def main():
    # cmdline arguments #
    if len(sys.argv) != 4:
        sys.exit("Error: incorrect number of arguments.\nFor help use -help")

    if sys.argv[1] == "-h" or sys.argv[1] == "-help":
        sys.exit("$ python Puzzle_Recognition image_name.jpg verti_roi horiz_roi")

    file_type = sys.argv[1].split('.')[-1]
    if file_type != "png" and file_type != "jpg":
        print(file_type)
        sys.exit("Error: Incorrect file type. .jpg & .png only")

    if not is_floatstring(sys.argv[2]):
        sys.exit("Error: argument 2 must be a decimal number between 0 and 1")

    if not is_floatstring(sys.argv[3]):
        sys.exit("Error: argument 3 must be a decimal number between 0 and 1")

    # Load Image #
    # color_img = cv2.imread(sys.argv[1])  # orignal color image, testing only

    gray_img = cv2.imread(sys.argv[1], flags=cv2.IMREAD_GRAYSCALE)  # grayscale image

    # clip images to roi #

    roi_y = int(gray_img.shape[0] * float(sys.argv[2]))  # height of image * percentage of verti_roi
    roi_height = gray_img.shape[0] - (2 * roi_y)
    roi_x = int(gray_img.shape[1] * float(sys.argv[3]))  # width of image * percentage of horizi_roi
    roi_width = gray_img.shape[1] - (2 * roi_x)
    roi_img = gray_img[roi_y:roi_y + roi_height, roi_x:roi_x + roi_width]

    # Image Processing #
    blur = cv2.GaussianBlur(roi_img, (3, 3), 0)  # remove noise from image

    thresh = cv2.threshold(blur, 200, 255, cv2.THRESH_BINARY_INV)[1]  # keep only dark lines

    # Find Puzzle #
    boundary = findPuzzleBoundary(thresh)
    if not boundary.all():
        sys.exit("Unable to find Puzzle")

    # Read cells of puzzle #
    puzzle_cell_numbers = readCells(blur, boundary)

    # write puzzle to csv file#
    writeResultToFile(puzzle_cell_numbers)
    # final_img = cv2.drawContours(color_img, [boundary], -1, (0, 0, 255), 3)  # draw the puzzle border
    # testing purposes
    #cv2.namedWindow("squares", flags=(cv2.WINDOW_NORMAL + cv2.WINDOW_KEEPRATIO))
    #cv2.resizeWindow("squares", 500, 500)
    # cv2.imshow("squares", final_img)  # open image in a window
    # cv2.waitKey(0)  # wait for a key press
    # cv2.destroyAllWindows()  # close window
    return


if __name__ == "__main__":
    main()
