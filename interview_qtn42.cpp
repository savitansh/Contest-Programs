#include <iostream>
using namespace std;

int ways[2][10000];
	
int main(){
	int n,m;
	cin>>n>>m;
	ways[0][n] = 1;
	
	for(int i=1; i<=n; i++){
		for(int k=1; k<m; k++){
	
	for(int j=n; j<=n*m; j++){
		ways[1][j] = ways[0][j];
	}
	for(int j=n; j<=n*m; j++){
		if(ways[0][j] > 0){
			ways[1][j+k]++;// = ways[0][j] + ways[1][j+k];
		}
	}
	for(int j=n; j<=n*m; j++){
		ways[0][j] = ways[1][j];
		ways[1][j] = 0;
	}
	}
	}
	for(int i=1; i<100; i++)
		cout<<ways[0][i]<<" ";
	//cout<<ways[5]<<endl;
}