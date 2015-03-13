/*
Let G=(V,E) be a connected, undirected graph.
 write a program to compute paths in G that traverses each edge in E exactly once in each direction. 

Example: If there is a Graph with edges in a triangle form V1, V2,V3
 we need to display all the paths from V1-V2-V3-V1 , V1-V3-V2-V1 

Note: Graph can have any number of nodes and there
 is no source or destination node given as input.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> lst[1000];
stack<int> stk,dump;
vector<int>::iterator it;

int visited[10000];

int dfs_traverse(int root){

	stk.push(root);
	int node;
	bool flag;
	
	while(!stk.empty()){
		node = stk.top();
		dump.push(node);
		stk.pop();
		flag = false;
		if(visited[node] == 0){
		visited[node] = 1;
		cout<<node<<endl;
		it = lst[node].begin();
		while(it!=lst[node].end()){
			if(visited[(*it)] == 0){
				stk.push(*it);
				flag = true;
			}
			it++;
		}	
		}
		if(flag == false){
			for(;!dump.empty();dump.pop()){
				cout<<dump.top();
			}
			cout<<endl;
		}
		
	}
}
int main(){
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		int v1,v2;
		cin>>v1>>v2;
		lst[v1].push_back(v2);
		lst[v2].push_back(v1);
	}
	dfs_traverse(0);	
}