#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <cstddef>
#include "../Puzzle_Solver/sudoku.c"
#define N 9
#ifdef __cplusplus
extern "C++" {
#endif
  bool valid(int *board, const size_t n, int guess, size_t row, size_t col);
  size_t countEmpty(int* board, size_t n);
  bool nextBox(int* board, const size_t n, size_t* row, size_t* col);
  bool Sudoku(int* board, size_t n, size_t i, size_t j);
#ifdef __cplusplus
}
#endif
int board[N];
void solve();
bool imageIsValid();
void constructPuzzle();
void clearBoard();
void processImage();

#endif
