#include <iostream>
#include <iomanip>
#include "Board.hpp"

Board(){
  goal = 32;
  max = 0;
  numRows = 3;
  numCols = 3;
  
  panel = new int*[numRows];
  for(int i = 0; i < numRows; i++){
    panel[i] = new int[numCols];
  }
}

Board(int m){
  goal = 32;
  max = 0;
  numRows = 3;
  numCols = 3;

  if(m >= 1){
    numRows = m;
    numCols = m;
  }

  panel = new int*[numRows];
  for(int i = 0; i < numRows; i++){
    panel[i] = new int[numCols];
  }
}

Board(int m, int n){
  goal = 32;
  max = 0;
  numRows = 3;
  numCols = 3;
  
  if(m >= 1 && n >= 1){
    numRows = m;
    numCols = n;
  }

  panel = new int*[numRows];
  for(int i = 0; i < numRows; i++){
    panel[i] = new int[numCols];
  }
}

~Board(){
  
}

void print(){
  for(int i = 0; i < numRows; i++){
    std::cout << "+";
    for(int j = 0; j < numCols; j++){
      std::cout << "----+";
    }
    std::cout << "\n";
    std::cout << "|";
    for(int j = 0; j < numCols; j++){
      if(panel[i][j] != 0){
        std::cout << std::setw(4) << panel[i][j] << "|";
      }
      if(panel[i][j] == 0){
        std::cout << std::setw(5) << "|";
      }
    }
    std::cout << "\n";
  }

  std::cout << "+";
  for(int i = 0; i < numCols; i++){
    std::cout << "----+";
  }
}
