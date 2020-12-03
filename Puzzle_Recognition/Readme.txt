To run program from command line: 
    $ python Puzzle_Recognition image_name.jpg verti_roi horiz_roi
    ex. python ./Puzzle_Recognition ./tests/puzzle.jpg .2 .1

image_name.jpg:
    - the file name of the image
    - can be .jpg or .png

verti_roi:
   - specifies the region of intrest in the image that the program
    will look for the puzzle inside of.
    - percentage of the height of the image
    - value between 0 - .5
    - ex. verti_roi = .1 image_height = 100
    100 * .1 = 10
    the roi starts 10 pixels down from the top of the image and 10
     pixels above the bottom of the image.

horiz_roi:
    - specifies the region of intrest in the image that the program
    will look for the puzzle inside of.
    - percentage of the width of the image
    - value between 0 - .5
    
The results are stored in csv format in unsolved_puzzle.csv    
