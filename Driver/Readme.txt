  Programmer:
  Jerusalem Moore

  -Driver currently takes a sudoku image with roi to process and solve. Output
  is either a solved puzzle or an invalid image error. Further implementation
  necessary for gui interaction.

  -Makefile compiles driver with necessary libs and creates a.out executable

  -Args: [executable] [imageName] [roi]

  Note:
  tests are the same test images provided in the Puzzle_Recognition directory,
  they are available in the Driver directory for easier testing.

  Optimal Roi's:
  I've found these two roi's to be accurate for our the first two tests. I'm
  still trying to find one that works for the others.
  01.jpg .92
  02.jpg .91
