/*
@author savitansh
1) In a Tic-Tac-Toe game two players are playing where player 0 
is denoted as 0 and player 1 is denoted as 1. Given a linked list
of moves made by the players ,determine who is the winner and in
how many moves he required for winning.

Struct Move {
   int p;    //Player number
   int x;    //x and y pos in the tic-tac-toi
   int y;
  struct Move *next;
};
*/
#include <iostream>
using namespace std;

struct Move {
   int p;    //Player number
   int x;    //x and y pos in the tic-tac-toi
   int y;
  struct Move *next;
};

int mat[4][4];
int count_0_x[4],count_0_y[4],count_1_x[4],count_1_y[4];
	
int result(Move *head){
	int x1,y1;
	Move *tmp = head;
	while(tmp!= NULL){
			x1 = tmp->x;
			y1 = tmp->y;

		if(tmp->p==0){
		count_0_x[x1]++;
		count_0_y[y1]++;
		mat[x1][y1] = 0;		
		}else{
		count_1_x[x1]++;
		count_1_y[y1]++;		
		mat[x1][y1] = 1;
		}
	}
	for(int i=1; i<=3; i++){
		if(count_0_x[i]==3 || count_0_y[i]==3)
			return 0;
		else if(count_1_x[i]==3 || count_1_y[i]==3)
			return 1;
	}
	if(mat[1][1]==mat[2][2] && mat[2][2]==mat[3][3]){
		if(mat[1][1]==0)
			return 0;
		else 
			return 1;
	}
	if(mat[1][3]==mat[2][2] && mat[2][2]==mat[3][1]){
		if(mat[1][3]==0)
			return 0;
		else 
			return 1;
	}
	return 3;
}

int main(){

}