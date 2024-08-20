//naive implementation based on https://www.youtube.com/watch?v=eAFcj_2quWI and geeks 4 geeks website
// cin with strings
#include <iostream>
#include <string>
using namespace std;

//basic function to print out the board matrix for debugging purposes 
void printBoard(int board[9][9]){
    for(int row = 0; row < 9; row ++){
        for(int col = 0; col < 9; col++){
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

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

  //checking that the sub-grid does not contain the num - fixed from geeks 4 geeks
  int row = r - (r%3); 
  int col = c - (c%3); 
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(board[i + row][j + col] == num){
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
        // cout << "reached the end of the col and row " << r+1 << " "; 
        // cout << endl;
        return solve(board, r+1, 0); 
    }

    //if it is not a blank we need to skip it!
    else if(board[r][c] != 0){
        // cout << "already had a value - column iterated to " << c+1;
        // cout << endl; 
        return solve(board, r, c+1); 
    }

    //(naive implementation) if we are in the middle of a column on row r, we need to find candidate values 
    //try to all combinations of numbers 
    else{
        for(int i = 1; i < 10; i++){
            //check that the number is actually valid in that cell
            if (isValid(board, r, c, i) == true){
                // cout << "Placing " << i << " at (" << r << "," << c << ")"; 
                // cout << endl;
                board[r][c] = i;
                // printBoard(board); 
                // cout << endl; 
                //recursive call to check that recursive backtracking of this newly edited board 
                if (solve(board, r, c+1) == true){
                    return true; 
                }
            }
            //means that it is not solveable so we must put it back to 0 
            board[r][c] = 0; 
        }
        //unsolvable 
        return false; 
    }
}


int main ()
{
    //added test case based on new york times
    int board[9][9] = { { 0, 9, 8, 0, 0, 0, 2, 0, 0 },
                       { 0 , 0, 3, 0, 4, 1, 9, 0, 0 },
                       { 4, 5, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 9, 0, 2, 8, 4, 0, 0 },
                       { 0, 6, 0, 0, 0, 0, 0, 7, 0 },
                       { 0, 0, 0, 0, 0, 9, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 5, 6 },
                       { 0, 0, 0, 6, 0, 0, 0, 0, 4 },
                       { 0, 0, 0, 0, 8, 0, 7, 0, 0 } };

    //added test case based on geeks for geeks 
    // int board[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(solve(board, 0, 0) == true){
        printBoard(board);
    }

    else{
        cout << "Unsolveable!";
    }

}