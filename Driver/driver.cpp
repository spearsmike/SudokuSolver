#include "driver.h"
#include "Puzzle_Solver/solver.c"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#define VERSION "python3"
/*
  -integration for gui
  -ask curtis if hroi and vroi need to be arguments or can that be automated on
  his end
  -is valid function is expecting a status.txt from curtis's python script
  -is michael still expecting me to use .c version of the solver
*/
#define STATUS "status.txt"
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
bool solve(){
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
    return false;
  }
  return true;
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
      remove("status.txt");
      return false;
    }
  }
  remove("status.txt");
  return true;
}
/*
  construct a 2d array from the image results for solving
*/
bool constructPuzzle(){
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
  remove("unsolved_puzzle.csv");
  // utility for outputting array contents
  cout << "Board produced by image processor: \n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << board[i*N+j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  string answer;
  while(true){

    //cin.ignore();
    cout << "Is this the correct puzzle?(y/n)\n";
    getline(cin,answer);
    if(answer == "y"){
      return true;
    }
    else if(answer == "n"){
      return false;
    }
    else{
      cout << "Invalid answer.\n";
    }
  }
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
  const char* procExecutable = "Puzzle_Recognition/Puzzle_Recognition.py";
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
    if(constructPuzzle()){
        if(!solve()){
          cout << "No possible solution" << endl;
          return 0;
        }
    }
    else{
      cout << "Sorry, try a clearer image or a more accurate roi\n";
      return 0;
    }
  }
  else{
    return 0;
  }
  std::ofstream solutionFile;
  string answer;
  while(true){
    cout << "Would you like to save the solution?(y,n)\n";
    getline(cin, answer);
    if(answer == "y"){
      cout << "File saved to solution.txt.\n";
      solutionFile.open ("solutions/solution.txt");
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          solutionFile << board[i*N+j] << " ";
        }
        solutionFile << endl;
      }
      solutionFile.close();
      break;
    }
    else if(answer == "n"){
      cout << "Closing...";
      break;
    }
    else{
      cout << "Invalid option.\n";
    }
  }


  return 0;

}
//TRYING TO CONSTRUCT INTERFACE
// #include "driver.h"
// #include "../Puzzle_Solver/solver.c"
//
// #define PYTHON "python3"
// /*
//   -integration for gui
//   -ask curtis if hroi and vroi need to be arguments or can that be automated on
//   his end
//   -is valid function is expecting a status.txt from curtis's python script
//   -is michael still expecting me to use .c version of the solver
// */
// #define STATUS "./status.txt"
// /*
//   try to solve the puzzle and return the result if
//   successful. return an error message otherwise
// */
// void solve(){
//   if(Sudoku(board, N, 0, 0)){
//     cout << "Solution Found\n";
//     for(int i = 0; i < N; i++){
//       for(int j = 0; j < N; j++){
//         cout << board[i*N+j] << " ";
//       }
//       cout << endl;
//     }
//   }
//   else{
//     cout << "No possible solution" << endl;
//   }
// }
// /*
//   check if the image processor returned a valid puzzle
// */
// bool imageIsValid(){
//   string successMsg = "success";//msg to scan for validity
//   string line;
//   ifstream status(STATUS);//obtain status file
//   if(status.is_open()){
//     getline(status,line);
//     if(successMsg.compare(line) != 0){//scan for errorMsg in status file
//       status.close();
//       cout << "Error, image is not valid, please try again." << endl;
//       status.close();
//       return false;
//     }
//   }
//   return true;
// }
// /*
//   construct a 2d array from the image results for solving
// */
// void constructPuzzle(){
//   int num;
//   int count = 9;
//   ifstream input("unsolved_puzzle.csv");
//   string line;
//   vector<vector<string>> boardVector;
//   while(getline(input, line)){
//     stringstream lineStream(line);
//     string cell;
//     vector<string> row;
//     while(getline(lineStream, cell, ',')){
//       row.push_back(cell);
//     }
//     boardVector.push_back(row);
//   }
//     for(int i = 0; i < N; i++){
//       for(int j = 0; j < N; j++){
//         board[i*N+j] = stoi(boardVector[i][j], NULL);
//     }
//   }
//   // utility for outputting array contents
//   cout << "Board produced by image processor: \n";
//   for(int i = 0; i < N; i++){
//     for(int j = 0; j < N; j++){
//       cout << board[i*N+j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
// }
// /*
//   clean board for new instance
// */
// void clearBoard(){
//   for(int i = 0; i < 9; i++){
//     for(int j = 0; j < 9; j++){
//       board[i*N+j] = 0;
//     }
//   }
// }
// /*
//   run py script with args from stdin
// */
// void processImage(string imageName, string roi){
//   string procExecutable = "../Puzzle_Recognition/Puzzle_Recognition.py";
//   // char* imageName = argv[1];
//   // char* roi = argv[2];
//   string python = "python3";
//   string command = python + " " + procExecutable + " " + imageName + " " + roi;
//   const char* cCommand = command.c_str();
//   system(cCommand);
// }
// void process(){
//   if(imageIsValid()){
//      constructPuzzle();
//      solve();
//   }
//   clearBoard();
// }
//
// int main(int argc, char* argv[]){
//   bool running = true;
//   ifstream ifile;
//   string storageLocation = "../storage/";
//   string imageName = "";
//   string roi;
//   string exit = "exit";
//   string userCommand;
//   string upload = "upload image";
//   string uploadCommand;
//   std::locale loc;
//   int pos;
//   const char** argsForProcessing;
//   cout << "Please type a following command: \n";
//   cout << "1: Upload image\n";
//   cout << "2: Exit\n";
//   while(running){
//     getline(cin, userCommand);
//     for(int i = 0; i < userCommand.length(); i++){
//       std::tolower(userCommand[i], loc);
//     }
//     if(userCommand == exit){
//       running = false;
//       return 0;
//     }
//     else if(userCommand == upload){
//       cout << "Please enter uploaded image name:(Make sure image is in storage folder)\n";
//       cin >> imageName;
//       ifile.open(storageLocation + imageName);
//       pos = imageName.length() - 1;
//       if(pos > 0){
//         if(imageName.substr(pos-3, pos) == ".jpg" || imageName.substr(pos-3, pos) == ".png"){
//           if(ifile) {
//             cout<<"File found:\n";
//             cout << "Please enter roi(between 0 and 1):\n";
//             cin.ignore();
//             getline(cin, roi);
//             while(stoi(roi) < 0 || stoi(roi) > 1){
//               cout << "Error, invalid roi.\n";
//               //cin.ignore();
//               getline(cin,roi);
//             }
//             cout << "Processing...\n";
//             processImage(imageName, roi);
//             process();
//           }
//           else{
//            cout<<"Error image file not in storage";
//          }
//        }
//        else{
//          cout << "Error, make sure image is a valid .jpg or .png file.\n\n";
//          cout << "Please type a following command: \n";
//          cout << "1: Upload image\n";
//          cout << "2: Exit\n";
//          cin.ignore();
//          continue;
//        }
//       }
//       else{
//         cout << "Error, make sure image is a valid .jpg or .png file.\n\n";
//         cout << "Please type a following command: \n";
//         cout << "1: Upload image\n";
//         cout << "2: Exit\n";
//         cin.ignore();
//         continue;
//       }
//     }
//     else{
//       cout << "Error, invalid option.\n\n";
//       cout << "Please type a following command: \n";
//       cout << "1: Upload image\n";
//       cout << "2: Exit\n";
//       continue;
//     }
//   }
//   if(argc < 3){
//     cout << "Not enough arguments: run [executable] [imagename] [roi]\n";
//   }
//
//   //check if valid and solve
//
//
//
//
//
//
// }
