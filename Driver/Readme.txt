  Programmer:
  Jerusalem Moore
  
  -I set driver to be the root folder so that you only need the makefile inside to run the application
    Additions:
      -solutions folder holds saved solution
      -driver asks if user wants to save solution
      -driver asks if sudoku puzzle was correctly copied for solving
      
  -Driver currently takes a sudoku image with roi to process and solve. Output
  is either a solved puzzle or an invalid image error. Further implementation
  necessary for gui interaction.
  
  How to use driver:
    -Makefile compiles driver with necessary libs and creates a.out executable
    -Args: [executable] [imageName] [roi] (imageName needs directory location of images. i.e. tests/filename to test image in driver)
  
  Optimal Roi's:
    Need to find working tests and roi's for more images
  
  Note:
    tests are the same test images provided in the Puzzle_Recognition directory,
    they are available in the Driver directory for easier testing.
