// #ifndef N
// #define N 9
// #endif

#ifdef C
enum bool {false, true};
typedef size_t bool;
#endif

// checks if the the element at row, col is valid
bool valid(int* board, const size_t n, int guess, size_t row, size_t col);

// counts the number of empty boxes
size_t countEmpty(int* board, size_t n);

// returns true if a next box is found
// sets row and col to the next box
bool nextBox(int* board, const size_t n, size_t* row, size_t* col);

// solves a Sudoku* boardize nxn
// i and j start at 0
// returns true if there is a solution
bool Sudoku(int* board, size_t n, size_t i, size_t j);
