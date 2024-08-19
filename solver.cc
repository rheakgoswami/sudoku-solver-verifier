// cin with strings
#include <iostream>
#include <string>
using namespace std;

//checks if the number is valid to begin with to reverse backtrack 
//board represents the sudoku board, variable r represents the row of the empty space we seek to fill, and c represents the column of the empty space we seek to fill
//num is the number we are currently checking if it is valid 
bool isValid(int board[9][9], int r, int c, int num){
  //checking that the col does not contain the num 
  for(int i = 0; i < 9; i++){
    if(board[i][c] == num){
      return false; 
    }
  }

  //checking that the row does not contain the num 
  for(int i = 0; i < 9; i++){
    if(board[r][i] == num){
      return false; 
    }
  }

  //checking that the sub-grid does not contain the num 
  int row = r%3*3; 
  int col = c%3*3; 
  for(int i = row; i < row+3; i++){
    for(int j = col; j < col+3; j++){
      if(board[i][j] == num){
        return false; 
      }
    }
  }

  //only if the number is not present in the sub-grid, row, or column
  return true; 
}

//uses recursive backtracking to solve the sudoku board

int main ()
{
  for(int i = 0; i < 3; i++){
    cout << "Yes x " << i;
    cout << endl;
  }
}