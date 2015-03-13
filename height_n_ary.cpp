#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > g;
int visited[10000];
int h = 0;

int dfs(int source, int dist){
	if(dist > h)
		h = dist;

	vector<int>neigh = g[source];
	int sz = neigh.size();
	for(int i=0; i<sz; i++){
		if(visited[neigh[i]] == 0){
			visited[neigh[i]] = 1;
			dfs(neigh[i],dist+1);
		}
	}
	return 0;
}

int main(){
	int par[1000];
	int n;
	cin>>n;

	for(int i=1; i<n; i++){
		cin>>par[i];
		g[par[i]].push_back(i);	
	}

	int source = 0;
	visited[source] = 1;
	dfs(source,0);
	cout<<h<<endl;
}