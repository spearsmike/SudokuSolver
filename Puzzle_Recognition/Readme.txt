To run program from command line: 
    $ python Puzzle_Recognition image_name.jpg roi
    ex. python ./Puzzle_Recognition ./tests/puzzle.jpg .7

image_name.jpg:
    - the file name of the image
    - can be .jpg or .png

roi:
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