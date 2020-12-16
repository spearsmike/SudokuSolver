#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <cstddef>
#include "../Puzzle_Solver/solver.h"
#define N 9
int board[N];
bool solve();
bool imageIsValid();
bool constructPuzzle();
void clearBoard();
bool processImage();

#endif
