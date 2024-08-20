//naive implementation based on https://www.youtube.com/watch?v=eAFcj_2quWI
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

//uses recursive backtracking to solve the sudoku board - can be a way to figure out if its solveable 
bool solve(int board[9][9], int r, int c){
    //if we reach beyond the last row that means we have solved it!
    if(r == 9){
        return true; 
    }

    //if we reach the last column we have to recurse back to the next row
    else if(c == 9){
        return solve(board, r+1, 0); 
    }

    //if it is not a blank we need to skip it!
    else if(board[r][c] != 0){
        return solve(board, r, c+1); 
    }

    //(naive implementation) if we are in the middle of a column on row r, we need to find candidate values 
    //try to all combinations of numbers 
    else{
        for(int i = 1; i < 10; i++){
            //check that the number is actually valid in that cell
            if (isValid(board, r, c, i) == true){
                board[r][c] = i;
                //recursive call to check that recursive backtracking of this newly edited board 
                if (solve(board, r, c+1) == true){
                    return true; 
                }
                //means that it is not solveable so we must put it back to 0 
                board[r][c] = 0; 
            }
        }
        //unsolvable 
        return false; 
    }
}

void printBoard(int board[9][9]){
    for(int row = 0; row < 9; row ++){
        for(int col = 0; col < 9; col++){
            cout << board[row][col] << " ";
        }
    }
    cout << endl;
}


int main ()
{
    for(int i = 0; i < 3; i++){
        cout << "Yes x " << i;
        cout << endl;
    }
}