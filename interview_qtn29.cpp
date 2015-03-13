/*
rat in maze length of shortest path
e.g -

5
.S.##
##...
#.#.#
...##
...D.

*/
#include <iostream>
#include <deque>
using namespace std;

int path_length[1000];
int G[1000][1000];
int visited[10000];

deque<int> queue;
int nodes;

int do_bfs(int source){
	queue.push_back(source);
	while(!queue.empty()){
		int node = queue.front();
		queue.pop_front();

		visited[node] = 1;
		for(int k=0; k<nodes; k++){
			if(G[node][k] == 1 && visited[k]==0){
				queue.push_back(k);
				path_length[k] = path_length[node] + 1;
			}
		}
	}
	return 0;
}

string maze[1000];

int main(){
	int n;
	cin>>n;

	nodes = n*n;

	for(int i=0; i<n; i++)
		cin>>maze[i];
	int source,destination;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(maze[i][j] == '.' || maze[i][j]=='S' || maze[i][j]=='D'){
				for(int k=i-1; k<=i+1; k++){
					for(int l=j-1; l<=j+1; l++){
						if(k>=0 && k<n && l>=0 && l < n && maze[k][l] =='.'  && (k != i && l != j)){
							G[i*n+j][k*n+l] = 1;
							cout<<maze[k][l];
							cout<<i*n+j<<","<<k*n+l<<":"<<i<<","<<j<<","<<k<<","<<l<<endl;
						}
					}
				}
			}else if(maze[i][j] == 'D')
			destination = i*n+j;
			else if(maze[i][j] == 'S')
			source = i*n + j;	
		}
	}
for(int i=0; i<25; i++){
	for(int j=0; j<25; j++)
		cout<<G[i][j];
	cout<<endl;
}	

do_bfs(source);
cout<<path_length[destination]<<endl;
return 0;
}