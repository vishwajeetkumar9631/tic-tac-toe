#include<iostream>
using namespace std;

string board[9]={" "," "," "," "," "," "," "," "," "};
int player=1;
int position = 0;

void introduction (){
   cout<<"press [ENTER] to begin: ";
   getchar(); //haults the screen 
   cout<<"\n";
   cout<<endl;
   cout<<"****************"<<endl;
   cout<<"TIC-TAC-TOE"<<endl;
   cout<<"****************"<<endl;

   cout<<"PLAYER 1 " "-> X"<<endl;
   cout<<"PLAYER 2" " ->  0"<<endl;
   cout<<"3x3 grid is shown below "<< endl<< endl;
   cout<<"     |     |      "<<endl;
   cout<<"  1  |  2  |  3   "<<endl;
   cout<<"_____|_____|______"<<endl;
   cout<<"     |     |      "<<endl;
   cout<<"  4  |  5  |  6   "<<endl;
   cout<<"_____|_____|______"<<endl;
   cout<<"     |     |      "<<endl;
   cout<<"  7  |  8  |  9   "<<endl;
   cout<<"     |     |      "<<endl;
 }
 bool is_winner(){
   bool winner =false;
   // checking the row 
   if((board [0]==board[1])&&(board[1]==board[2]) && board[0] !=" "){
      winner=true;
   }
   else if((board[3]==board[4])&&(board[4]==board[5])&& board[3]!=" "){
      winner=true;
   }
   else if((board[6]==board[7])&& (board[7]==board[8])&& board[6]!=" "){
      winner=true;
   }
   // checking the column 
   if(( board[0]==board[3])&&(board[3]==board[6])&& board[0] !=" "){
      winner=true;
   }
   if(( board[1]==board[4])&&(board[4]==board[7])&& board[1] !=" "){
      winner=true;
   }
   if(( board[2]==board[5])&&(board[5]==board[8])&& board[2] !=" "){
      winner=true;
   }
   // checking the daigonal
   if(( board[0]==board[4])&&(board[4]==board[8])&& board[0] !=" "){
      winner=true;
   }
   if(( board[2]==board[4])&&(board[4]==board[6])&& board[2] !=" "){
      winner=true;
   }
 }
 bool filled_up() {
      bool filled=true;
      for(int i=0;i<9;i++){
        if (board[i]==" "){
         filled=false;
        }
      }return filled;
   }

void draw()
{ 
   cout<<"     |     |      "<<endl;
   cout<<"  "<<board[0]<<"  | "<<board[1]<<"   |  "<<board[2]<<"  "<<endl;
   cout<<"_____|_____|______"<<endl;
   cout<<"     |     |      "<<endl;
   cout<<"  "<<board[3]<<"  | "<<board[4]<<"   |  "<<board[5]<<"  "<<endl;
   cout<<"_____|_____|______"<<endl;
   cout<<"     |     |      "<<endl;
   cout<<"  "<<board[6]<<"  | "<<board[7]<<"   |  "<<board[8]<<"  "<<endl;
   cout<<"     |     |      "<<endl;

}
void set_position(){
   cout<<"player"<< player<<"('s (Enter 1:9))";
   while(!(cin>>position)){
      cout<< "please enter a valid no between (1:9) "<<endl;
      cin.clear();
      cin.ignore();

   }
   while(board[position-1]!=" "){
      cout<<"opps ,that position is already filled\n try again \n";
      cout<<" player"<< player<<"'s True (Enter 1-9): ";
      cin>>position;
      cout<<endl;
   }
}
void update_board(){
   if(player % 2==1 ){
      board[position -1 ]= "X";

   }else{
      board[position-1]="0";

   }
}
   void change_player(){
      if (player==1 ){
         player++;
      }else{
         player--;
      }
   }
   void take_turn(){
      while (!is_winner( ) || !filled_up()){
         set_position();
         update_board();
         change_player();
         draw();

      }
   }
   void end_game(){
      if( is_winner()){
         cout<< " there is a winner "<< endl;
      }else if (filled_up()){
         cout<<" there is a tie "<<endl;
      }
   }



 int main(){
    introduction();
    is_winner();
    filled_up();
    draw();
    set_position();
    update_board();
    change_player();
    take_turn();
   end_game();
   

 }
