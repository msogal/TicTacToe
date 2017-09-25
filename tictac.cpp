#include <iostream>
#include <cstring>
using namespace std;
void printBoard(char nboard[3][3]);
int main(){
  char board[3][3];
  //set the whole board to blank
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j]=' ';
    }
  }
  //print the board
  printBoard(board);
  return 0;
}
void printBoard(char nboard[3][3]){
  //print column adresses
  cout<<"\t1\t2\t3\t"<<endl;
  //print row addresses
  for(int rows = 0; rows < 3; rows++){
    char loadboard[7];
    strcpy(loadboard, "a\t \t \t ");
    loadboard[0] = ('a' +rows);
     for(int columns = 0; columns < 3; columns++){
      loadboard[(2*columns)+2] =nboard[rows][columns];
      }
    cout<<loadboard<<endl;
  }
 
}
