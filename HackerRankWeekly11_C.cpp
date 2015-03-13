#include <iostream>
#include <vector>
using namespace std;

std::vector<int> edge_list[200000];
long long int weight[200000],old_weight[200000];
int visited[200000];
bool pruned[200000];

int do_dfs(int node_idx){
	visited[node_idx] = 1;
	for (int i = 0; i < edge_list[node_idx].size(); ++i){

		if(visited[edge_list[node_idx][i]] == 0){

			weight[node_idx] += do_dfs(edge_list[node_idx][i]);
		}
	}
	return weight[node_idx];
}

int min_weight_idx(int n){
	int j = -1;
	int min_weight = -1;
	for (int i = 1; i <= n; ++i)
	{	
		if(weight[i] <= min_weight){
			min_weight = weight[i];
			j = i;
		}
	}
	return j;
}

int prune_node(int to_prune, int node_idx, bool flag){
	cout<<to_prune<<" "<<node_idx<<flag<<endl;
visited[node_idx] = 1;
	for (int i = 0; i < edge_list[node_idx].size(); ++i){

		if(visited[edge_list[node_idx][i]] == 0 && edge_list[node_idx][i] != to_prune && flag ==false){
			prune_node(to_prune, edge_list[node_idx][i], false);
		}	else if(edge_list[node_idx][i] == to_prune && flag == false && visited[edge_list[node_idx][i]] == 0){
			weight[edge_list[node_idx][i]] = 0;
			pruned[edge_list[node_idx][i]] = true;
			prune_node(to_prune,edge_list[node_idx][i],true);
		}	else if(flag == true && visited[edge_list[node_idx][i]] == 0){
			pruned[edge_list[node_idx][i]] = true;
			pruned[node_idx] = true;
			weight[edge_list[node_idx][i]] = 0;
			weight[node_idx] = 0;
			prune_node(to_prune	,edge_list[node_idx][i],true);
		}
	}
	return 0;
}

int main(){

	int n,u,v,k;
	cin>>n>>k;
	for (int i = 1; i <= n; ++i)
	{
		cin>>weight[i];
		old_weight[i] = weight[i];
	}

	for (int i = 1; i < n; ++i)
	{
		cin>>u>>v;
		edge_list[u].push_back(v);
		edge_list[v].push_back(u);
	}
	visited[1] = 1;
	do_dfs(1);
		

	cout<<weight[1]<<endl;

	for (int i = 0; i < k; ++i)
	{
		int j = min_weight_idx(n);
		if(j != -1 && j != 1){
			for (int i = 1; i <= n; ++i){
				visited[i] = 0;
			}
			prune_node(j,1,false);
		}	else if(j == 1){
			cout<<0<<endl;
			return 0;
		} else
		break;
	}
	for (int i = 1; i <= n; ++i){
		if(pruned[i] == false)
			weight[i] = old_weight[i];
		visited[i] = 0;
	}
	do_dfs(1);
	cout<<weight[1]<<endl;

return 0;
}