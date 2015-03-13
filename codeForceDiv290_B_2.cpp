#include <iostream>
#include <string>
using namespace std;

char M[50][50];
	int n=0,m=0;
	int visited[51][51];

int start,end;

bool find_cycle(int i, int j, char c){
	if(i<0 || i>=n)
		return false;
	if(j<0 || j>=m)
		return false;

	if(visited[i][j] == 2)
		return true;

	bool res = false;
	visited[i][j] = 1;
	
	if(i-1>=0 && M[i-1][j] == c && visited[i-1][j] != 1){
		bool r = find_cycle(i-1,j,c);
	res = res || r;
		}
	
	if(j>=1 && M[i][j-1] == c && visited[i][j-1] != 1){
		bool r = find_cycle(i,j-1,c);
	res = res || r;
		
		}
	

	if(i<n-1 && M[i+1][j] == c && visited[i+1][j] != 1){
		bool r = find_cycle(i+1,j,c);
	res = res || r;
		
		}
	if(j<m-1 && M[i][j+1] == c && visited[i][j+1] != 1){
		bool r = find_cycle(i,j+1,c);
		res = res || r;
		
	}
	visited[i][j] = 2;

	return res;
}

int main(){
	cin>>n>>m;

	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; j<m; j++)
			M[i][j] = s[j];
	}

	for(char c='A';c<='Z'; c++){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
		if(M[i][j] == c && visited[i][j]==0){
			bool res = find_cycle(i,j,c);
			//cout<<res<<endl;
			if(res == true)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			visited[i][j] = 0;
	}

	cout<<"No"<<endl;
	return 0;
}