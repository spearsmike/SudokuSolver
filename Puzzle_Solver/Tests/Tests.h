#include <cxxtest/TestSuite.h>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include "../solver.h"

using std::to_string;
using std::string;

class Tests : public CxxTest::TestSuite
{
public:
    void read_puzzle(size_t file_index, bool solution, std::string difficulty, int* puzzle, size_t n)
    {
        string file_name = to_string(n) + "_";
        file_name += (solution) ? "sol" : "nosol";
        file_name += "_" + difficulty + "_" + to_string(file_index) + ".csv";
        std::ifstream puzzle_file(file_name);
        if(puzzle_file.fail())
            TS_FAIL("Failed to open " + file_name + ".");
        
        string row;
        string num;
        for(int i=0; i<n; i++)
        {
            std::getline(puzzle_file, row);
            std::stringstream ss(row);
            for(int j=0; j<n; j++)
            {
                std::getline(ss, num, ',');
                puzzle[i*n+j] = num=="X" ? 0 : std::stoi(num);
            }
        }
    }

    void printPuzzle(int* puzzle, int n)
    {
        std::clog << '\n';
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                std::clog << puzzle[i*n+j] << ' ';
            }
            std::clog << '\n';
        }
    }

    void test_9x9_medium()
    {
        const size_t n = 9;
        int puzzle[n*n];
        read_puzzle(1, true, "medium", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
        read_puzzle(6, true, "medium", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_hard()
    {
        const size_t n = 9;
        int puzzle[n*n];
        read_puzzle(2, true, "hard", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_vhard()
    {
        const size_t n = 9;
        int puzzle[n*n];
        read_puzzle(3, true, "vhard", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
        read_puzzle(4, true, "vhard", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
        read_puzzle(5, true, "vhard", puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_medium_nosol()
    {
        const size_t n = 9;
        int puzzle[n*n];

        read_puzzle(7, false, "medium", puzzle, n);
        if(Sudoku(puzzle, n, 0, 0))
        {
            printPuzzle(puzzle, n);
            TS_FAIL("This isn't a solution.");
        }
    
        read_puzzle(8, false, "medium", puzzle, n);
        if(Sudoku(puzzle, n, 0, 0))
        {
            printPuzzle(puzzle, n);
            TS_FAIL("This isn't a solution.");
        }
        
        read_puzzle(9, false, "medium", puzzle, n);
        if(Sudoku(puzzle, n, 0, 0))
        {
            printPuzzle(puzzle, n);
            TS_FAIL("This isn't a solution.");
        }
    }
    // 16x16 board isn't recognized and the solver takes too long
    // void test_16x16_1()
    // {
    //     const size_t n = 16;
    //     int puzzle[n*n];
    //     read_puzzle(1, true, p"hard", uzzle, n);
    //     TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    // }
    // void test_16x16_2()
    // {
    //     const size_t n = 16;
    //     int puzzle[n*n];
    //     read_puzzle(2, true, p"hard", uzzle, n);
    //     TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    // }
    // void test_16x16_3()
    // {
    //     const size_t n = 16;
    //     int puzzle[n*n];
    //     read_puzzle(3, false, "hard", puzzle, n);
    //     TS_ASSERT(!Sudoku(puzzle, n, 0, 0));
    // }
};