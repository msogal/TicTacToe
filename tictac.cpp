#include <iostream>
#include <cstring>
using namespace std;
void printBoard(char nboard[3][3]);
bool checkWin(char nboard[3][3], char nplayer);
bool checkTie(char nboard[3][3]);
int main(){
  bool playing = true;
  char player = 'X';
  char board[3][3];
  int xwins = 0;
  int owins = 0;
  int ties = 0;
  //set the whole board to blank
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j]=' ';
    }
  }
  cout<<"X wins: "<<xwins<<"\t"<<"O wins: "<<owins<<"\t"<<"Ties: "<<ties<<endl;
  printBoard(board);
  while(playing){
    //print the board
    // printBoard(board);
    //prompt the move
    cout<<"Input you move as: letternumber. Example: a1"<<endl;
    char move[3];
    cin.get(move,3);
    cin.ignore(80,'\n');
    int x = move[0]-97;
    int y = move[1] - 49;
    //check for a valid move
    //    check to see if that space exists
    while(!((x>=0&&x<=2)&&(y>=0&&y<=2))) {
     cout<<"that is an invalid input. Please put in a different move"<<endl;
     cin.get(move,3);
     cin.ignore(80, '\n');
     x= move[0]-97;
     y = move[1]-49;
    }
    //     check to see if that space is empty
      while(!(board[x][y]==' ')){
	cout<<"There is already a piece there. Please put in a different move!"<<endl;
	cin.get(move,3);
	cin.ignore(80, '\n');
	x = move[0]-97;
	y = move[1]-49;
      }
    //make the move
    board[x][y] = player;
    //print the board
    printBoard(board);
    //check for victory
    if(checkWin(board, player)){
      playing = false;
      cout<<player<<" won!"<<endl;
      if(player=='X'){
	xwins++;
      }else if(player=='O'){
	owins++;
      }
      //see if they want to play again
      char newgame = ' ';
      cout<<"Play again? y or n"<<endl;
      cin>>newgame;
      if(newgame=='y'){
	//reset the board
	playing = true;
      }
    }else if(checkTie(board)){
      playing = false;
      cout<<"Tie!"<<endl;
      ties++;
    }
    //switch players
    if(player=='X'){
      player= 'O';
    }else if(player=='O'){
      player= 'X';
    }
   
     
  }
  return 0;
}
void printBoard(char nboard[3][3]){
  //print victory counts
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
bool checkWin(char nboard[3][3], char nplayer){
  //check rows for wins
  bool win = false;
  for(int row = 0; row < 3; row++){
    int wincount = 0;
    for(int column = 0; column < 3; column++){
      if(nboard[row][column] == nplayer){
	//	cout<<"Inside IF Satement"<<endl;
      	wincount++;
	//	cout<<" Inside IF, the count is: "<<wincount<<endl;
      }
      // cout<<" Player " <<nplayer <<" Row "<<row<<" Column "<<column<<" Value "<<nboard[row][column]<< " Count "<<wincount<<endl;
      // cout<<"wincount for "<<row<<"is "<<wincount<<endl;
    }
    if(wincount == 3){
      // win = true;
      //cout<<nplayer<<" wins!"<<endl;
      return true;
    }
  }
  //check wins on columns
  for(int column = 0; column < 3; column++){
    int wincount = 0;
    for(int row = 0; row < 3; row++){
      if(nboard[row][column]==nplayer){
	//	cout<<"Inside IF statement"<<endl;
	wincount++;
      }
      // cout<<"Player "<<nplayer <<" Column "<<column<<" Row " <<row<<" Value "<<nboard[column][row]<<" Count "<<wincount<<endl;
      // cout<<"wincount for " <<column <<"s"<<wincount<<endl;
    }
    if(wincount==3){
      // win = true;
      // cout<<nplayer<<" wins!"<<endl;
      return true;
    }
  }
  //check diagonals
  if(nboard[0][0]==nplayer&&nboard[1][1]==nplayer&&nboard[2][2]==nplayer){
    win = true;
    // cout<<nplayer<<" wins!"<<endl;
    return win;
  }else if(nboard[0][2]==nplayer&&nboard[1][1]==nplayer&&nboard[2][0]==nplayer){
    win = true;
    // cout<<nplayer<<" wins!"<<endl;
    return win;
  }
  return false;
  
}
bool checkTie(char nboard[3][3]){
  for(int i = 0; i < 3; i++ ){
    for(int j = 0; j < 3; j++){
      if(nboard[i][j]==' '){
	return false;
      }
    }
  }
  return true;

}
