/*
cycle in a graph
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> edge_list[1000];
stack<int> stk;
stack<int> cycle_stk;
int visited[10000];

int do_dfs(int node){
	stk.push_back(node);
	while(!stk.empty()){
		int node = stk.pop();
		visited[node] = 1;
		for(it = edge_list[node].begin(); it != edge_list[node].end(); it++){
			if(visited[*it]==0)
			stk.push_back(*it);
			else{
				while(node != *it){
				cycle_stk.push_back(node);
					node = parent[node];
				}
				return -1;
			}
		}
	}
	return 0;
}

int main(){
	
}