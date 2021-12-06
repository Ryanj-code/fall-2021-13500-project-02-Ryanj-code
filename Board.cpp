#include <iostream>
#include "Board.hpp"
/*
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
*/
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
	vector <rc> emptyCells; 
    
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if(panel[i][j] == 0){
                rc newCell; 
                newCell.row = i;
                newCell.col = j;
                emptyCells.push_back(newCell);
            }
        }
    }

    if (emptyCells.size() > 0){
        int randNum = rand() % emptyCells.size() - 0;
        panel[emptyCells.at(randNum).row][emptyCells.at(randNum).col] = 1; 
        print();
    }
        if(noAdjacentSameValue() || emptyCells.size() == 0){
        std::cout << "Game over. Try again." << std::endl;
        exit(0);
    }	
}
/*
void Board::pressUp(){
	
}

void Board::pressDown(){
	int* temp = new int[numRows]; 
    int toWrite;
    for (int j = 0; j < numCols; j++){
        //initialize each element of temp to be 0
        for (int k = 0; k < numRows; k++)
            temp[k] = 0;

        //copy the non-zeros from the jth column
        //of panel to temp
        toWrite = numRows -1; //next position to write in temp
        for (int i = numRows-1; i >= 0; i--)
            if (panel[i][j] > 0){
               temp[toWrite] = panel[i][j];
               toWrite--;
            }

        for (int k = numRows-1; k > 0; k--) //? k >= 0 is not correct, it would result in out of index exception in expression temp[k-1].
            if (temp[k] == temp[k-1]){
               temp[k] *= 2;

               //MISS
               if (max < temp[k])
                  max = temp[k];

               temp[k-1] = 0;
               k--; //k-- to skip adjacent pair
               //temp[k-1] and temp[k-2]
               //since temp[k-1] is merged with
               //temp[k] already.
               //This line can be omitted after
               //setting temp[k-1] = 0;
               //since if temp[k-2] is not zero,
               //no way to merge since
               //temp[k-1] != temp[k-2],
               //if temp[k-2] is zero,
               //then 0 merged with 0 does not
               //result in any actual difference.
            }

        int i = numRows -1;  //to write in jth column of panel, starting from the last row since we press down key, whose row index is numRows-1. 
        int k = numRows -1; //can use for loop for k
        while (k >= 0) 
        {
            if (temp[k] > 0)
            {
               panel[i][j] = temp[k];
               i--;
            }
            k--;
        }

        //For the remaining elements in the jth column, pad with 0.
        while (i >= 0)
        {
            panel[i][j] = 0;
            i--;
        }
    }

    delete[] temp;
    temp = nullptr;

    //MISS
    int row = -1, col = -1;
    selectRandomCell(row, col);
}

void Board::pressLeft(){

}

void Board::pressRight(){

}
*/
