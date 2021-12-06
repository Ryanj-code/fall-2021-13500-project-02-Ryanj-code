#include <iostream>
#include "Board.hpp"

Board::Board(){
    target = 32;
    max = 0;
    numRows = 3;
    numCols = 3;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }
}

Board::Board(int m){
    target = 32;
    max = 0;

    if (m < 0){
        m = 3;
    }
    numRows = m;
    numCols = m;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }
}

Board::Board(int m, int n){
    target = 32;
    max = 0;

    if (m < 0 || n < 0){
        m = 3;
        n = 3;
    }
    numRows = m;
    numCols = n;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }
}

Board::~Board(){
    for(int i = 0; i < numRows; i++){
        delete[] panel[i];
    }
    delete[] panel;
}

void Board::print() const{
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            std::cout << "+----";
        }
        std::cout << "+\n";
        std::cout << "|";
        for (int j = 0; j < numCols; j++){
            if (panel[i][j] != 0){
                std::cout << "    " << panel[i][j] << "|";
            }
            if (panel[i][j] == 0){
                std::cout << "    |";
            }
        }
        std::cout << "\n";
    }

    for (int i = 0; i < numCols; i++){
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
}

bool Board::noAdjacentSameValue() const{
  for(int i = 0; i < numRows-1; i++){
    for(int j = 0; j < numCols-1; j++){
      if(panel[i][j] == panel[i+1][j] || panel[i][j] == panel[i][j+1]
	 || panel[i][j] == panel[i-1][j] || panel[i][j] == panel[i][j-1]){
	return false;
      }
    }
  }

  return true;
}

struct rc {
  int row;
  int col;
};
 

void Board::selectRandomCell(int& row, int& col){
  
}

void Board::pressUp(){

}

void Board::pressDown(){

}

void Board::pressLeft(){

}

void Board::pressRight(){

}
