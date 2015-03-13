/*
count number of islands
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int map[100][100];
int node_pt[100][100];
int visited[100000];
int n = 0;

vector<int> graph[10000];
deque<int> tmp_q;
vector<int>::iterator it;

bool is_queue_empty(){
	return tmp_q.empty();
}

int pop_node(){
	int data = tmp_q.front();
	tmp_q.pop_front();
	return data;
}
int add_to_queue(int data){
	tmp_q.push_back(data);
}

int nodes = 0;
int make_graph(){
	int t = 0,node1=0,node2=0;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j< n; j++){
			if(map[i][j] == 1)
			node_pt[i][j] = ++t;
		}
	}
	nodes = t;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1){
				for(int k=i-1;k<=i+1;k++){
					for(int l=j-1; l<=j+1; l++){
						if(k>=0 && k<n && l>=0 && l<n && map[k][l] == 1 && !(i==k && l==j)){
							node1 = node_pt[i][j];
							node2 = node_pt[k][l];
							//cout<<node1<<" "<<node2<<endl;
							graph[node1].push_back(node2);
							graph[node2].push_back(node1);
						}
					}
				}
			}
		}
	}
}

int bfs_traverse(int island_count){
	while(!is_queue_empty()){
		int node = pop_node();
		visited[node] = island_count;
		for(it = graph[node].begin(); it != graph[node].end(); it++){
			if(visited[*it] == 0){
				add_to_queue(*it);
			}
		}
	}
}

int island_count = 0;
int traverse(){
	for(int i=1; i<nodes; i++){
		if(visited[i] == 0){
			island_count++;
			add_to_queue(i);
			bfs_traverse(island_count);
			// cout<<i<<" ";
			 //for(it = graph[i].begin(); it!= graph[i].end(); it++){
			 //	cout<<*it<<" ";
			 //}
			cout<<endl;
		}
	}
	return island_count;
}

int main(){
	n=6;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int val;
			cin>>val;
			map[i][j] = val;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
	make_graph();	
	int island_count = traverse();
	cout<<island_count<<endl;
	return 0;
}