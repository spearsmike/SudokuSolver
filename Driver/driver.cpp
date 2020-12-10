#include "driver.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Python.h"
#define VERSION "python3"
/*
  -integration for gui
  -ask curtis if hroi and vroi need to be arguments or can that be automated on
  his end
  -is valid function is expecting a status.txt from curtis's python script
  -is michael still expecting me to use .c version of the solver
*/
#define STATUS "./status.txt"
using std::cout;
using std::vector;
using std::istringstream;
using std::endl;
using std::ifstream;
using std::string;
using std::cin;
using std::stringstream;
/*
  try to solve the puzzle and return the result if
  successful. return an error message otherwise
*/
void solve(){
  if(Sudoku(board, N, 0, 0)){
    cout << "Solution Found\n";
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cout << board[i*N+j] << " ";
      }
      cout << endl;
    }
  }
  else{
    cout << "No possible solution" << endl;
  }
}
/*
  check if the image processor returned a valid puzzle
*/
bool imageIsValid(){
  string successMsg = "success";//msg to scan for validity
  string line;
  ifstream status(STATUS);//obtain status file
  if(status.is_open()){
    getline(status,line);
    if(successMsg.compare(line) != 0){//scan for errorMsg in status file
      status.close();
      cout << "Error, image is not valid, please try again." << endl;
      status.close();
      return false;
    }
  }
  return true;
}
/*
  construct a 2d array from the image results for solving
*/
void constructPuzzle(){
  int num;
  int count = 9;
  ifstream input("unsolved_puzzle.csv");
  string line;
  vector<vector<string>> boardVector;
  while(getline(input, line)){
    stringstream lineStream(line);
    string cell;
    vector<string> row;
    while(getline(lineStream, cell, ',')){
      row.push_back(cell);
    }
    boardVector.push_back(row);
  }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        board[i*N+j] = stoi(boardVector[i][j], NULL);
    }
  }
  // utility for outputting array contents
  cout << "Board produced by image processor: \n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << board[i*N+j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
/*
  clean board for new instance
*/
void clearBoard(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      board[i*N+j] = 0;
    }
  }
}
/*
  run py script with args from stdin
*/
void processImage(int argc, char* argv[]){
  const char* procExecutable = "../Puzzle_Recognition/Puzzle_Recognition.py";
  char* imageName = argv[1];
  char* roi = argv[2];
  int bufferSize = strlen(VERSION) + strlen(procExecutable) + strlen(imageName) + strlen(roi);
  char command[bufferSize];
  strcpy(command, VERSION);
  strcat(command, " ");
  strcat(command, procExecutable);
  strcat(command, " ");
  strcat(command, imageName);
  strcat(command, " ");
  strcat(command, roi);
  system(command);
}
int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "Not enough arguments: run [executable] [imagename] [roi]\n";
  }
  processImage(argc, argv);

  //check if valid and solve
  if(imageIsValid()){
     constructPuzzle();
     solve();
  }
  clearBoard();





}
