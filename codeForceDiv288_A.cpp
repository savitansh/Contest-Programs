#include <iostream>
using namespace std;

int M[1000][1000];

int main(){
	int n,m;
	cin>>n>>m;
	int q;
	cin>>q;
	for(int i=1; i<=q; i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		M[x][y] = 1;
		if(x>=1 && y>=1 && M[x-1][y-1]==1 && M[x][y-1]==1 && M[x-1][y]==1){
			cout<<i<<endl;
			return 0;
		}else if(y+1<m && x>=1 && M[x][y+1]==1 && M[x-1][y]==1 && M[x-1][y+1]==1){
			cout<<i<<endl;
			return 0;
		}else if(x+1<n && y>=1 &&  M[x+1][y]==1 && M[x+1][y-1]==1 && M[x][y-1]==1){
			cout<<i<<endl;
			return 0;
		}else if(y+1<m && x+1<n && M[x][y+1]==1 && M[x+1][y]==1 && M[x+1][y+1]==1){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
}