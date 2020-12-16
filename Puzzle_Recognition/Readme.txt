To run program from command line: 
    $ python Puzzle_Recognition image_name.jpg roi
    ex. python ./Puzzle_Recognition ./tests/puzzle.jpg .7

image_name.jpg:
    - the file name of the image
    - can be .jpg or .png

roi:
    default is .7
    -The size of the region of intrest
    -A precentage of the smallest dimension of the image.
    if image is 1920x1080 and roi = .7
    1080*.7 = 756
    then the size of the roi box is 756x756 pixels
    located in the center of the image.
    
The results are stored in csv format in unsolved_puzzle.csv    

status.txt
    error: msg
    in-progress
    success

dependencies installation
$ sudo apt install python3.8 python3-pip
$ sudo apt install tesseract-ocr
$ sudo apt install python3-opencv
$ sudo pip3 install pytesseract

image requirements
-Puzzle be centered.
-Puzzle border must be lined up with the cameras box.
-Minimum of 1920x1080

tests images
roi = .7
10.jpg resolution to low.
11.jpg correct
12.jpg 2 read errors
13.jpg could not find puzzle
14.jpg 3 read errors
15.jpg 2 read errors
