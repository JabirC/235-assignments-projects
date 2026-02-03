#include <iostream>
#include <string>
#include <unistd.h>


void print_board(int **arr, int n){
  // std::cout << "[0;0H\n";    //Used during animation
  for(int i =0; i < n;i++){
    for(int j=0; j < n; j++){
      if(arr[i][j] == 1) std::cout << "Q";
      else std::cout << "#";
    }
    std::cout << std::endl;
  }
  // usleep(500000);      //Used during animation
}

//Checks the row for another queen
bool check_row(int **arr, int row, int col, int n){
  for(int k =col + 1; k <n; k++){
    if(arr[row][k] == 1) return false;
  }
  return true;
}

//Chekcs the collumn for another queen
bool check_col(int **arr, int row, int col, int n){
  for(int k =row + 1; k <n; k++){
    if(arr[k][col] == 1) return false;
  }
  return true;
}

//Checks diagonals for another queen
bool check_diag(int **arr, int row, int col, int n){
  for(int i =row +1, j = col + 1; i < n && j < n; i++, j++){
    if(arr[i][j] == 1) return false;
  }
  for(int i =row +1, j = col - 1; i < n && j >= 0; i++, j--){
    if(arr[i][j] == 1) return false;
  }
  return true;
}

//Checks rows, cols, and diagonals
bool check_valid(int **arr, int n){
  for(int i =0; i < n; i++){
    for(int j =0; j < n; j++){
      if(arr[i][j] == 1){
        if(!check_row(arr, i,j,n) || !check_col(arr, i, j, n) || !check_diag(arr, i, j, n)){
          return false;
        }
      }
    }
  }
  return true;
}

void solve_helper(int **arr,int row,int col,int queens, int n, int& solved){
  if(solved == 1) return; //If already solved, return
  arr[row][col] = 1;  // Places queen
  queens++; // number of queens on the board increased by one

  // print_board(arr,n);  //Used during animation
  if(!check_valid(arr,n)){
      arr[row][col] = 0; // If the queen is placed on an invalid square, remove it
      // print_board(arr,n); //Used during animation
      return;
  }
  else{
    if(queens == n){  // If there are already N queens on the board, solution is found
      print_board(arr,n);
      solved = 1;
      return;
    }
    else{
      //If the queen placed in this function is valid, loop through the rest of the rows and cols for solution
      for(int i = row +1; i < n; i++){
        for(int k = 0; k< n; k++){
          solve_helper(arr, i,k,queens,n,solved);
        }
      }

      // If no solution is found with this placement of the queen, remove the queen and go back to previous state
      arr[row][col] = 0;
      return;
    }
  }

}

void solve(int n){
  if(n == 2 || n == 3){
     std::cout << "No solution for board of size " << n << std::endl;
     return;
  }
  int size =n;
  int solved = 0;

  //Creates dynamic NxN array
  int **board = new int*[size];
  for(int i = 0; i < size; ++i){
      board[i] = new int[size];
  }

  //loops through row 0 to find a solution
  for(int k = 0; k < size ; k++){
    if(solved == 1) break;
    solve_helper(board, 0, k, 0, size, solved);
  }
}




int main(){
  solve(5);
  return 0;
}
