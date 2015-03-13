#include<iostream>
using namespace std;

int main(){
	
	int mat[20][20];
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>mat[i][j];
		}
	}

	char choice[20];
	cin>>choice;
	if(strcmp(choice,"right") == 0){
		for(int row=0; row<N; row++){
			bool change = false;
			while(change == false){
				for (int col = N-1; col > 0; col--)
				{
					
				}
			}
		}
	}
}
