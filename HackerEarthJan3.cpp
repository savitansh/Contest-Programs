	/*
	@author savitansh
	*/
	#include <iostream>
	#include <algorithm>
	#include <vector>
	#include <utility>
	using namespace std;

	vector<pair<int,int> > lst[100001];
	pair<int,int> wt;

	int visited[100001];
	long int max_w=-1;
	int max_n;

	int dfs(int node, long int weight){
		
		if(weight > max_w){
			max_w = weight;
			max_n = node;
		}

		int siz = lst[node].size();
		for(int i=0; i<siz; i++){
			wt = lst[node][i];
			if(visited[wt.first] == 0){
			visited[wt.first] = 1;
			dfs(wt.first, wt.second + weight);
			}
		}
		return 0;
	}

	int calc(){
		int n;
		cin>>n;
		max_w = -1;
		max_n = 0;
		for(int i=0; i<100001;i++)
			lst[i].clear();

		for(int i=0; i<n-1; i++){
			int a,b,c;
			cin>>a>>b>>c;
			wt = make_pair(b,c);
			lst[a].push_back(wt);
			wt = make_pair(a,c);
			lst[b].push_back(wt);
		}
		for(int i=0; i<100001;i++)
			visited[i] = 0;
		visited[1] = 1;
		dfs(1,0);
		for(int i=0; i<100001;i++)
			visited[i] = 0;

		max_w = -1;
		visited[max_n] = 1;
		dfs(max_n,0);
		int cost = 0;
		if(max_w > 10000)
			cost = 10000;
		else if(max_w > 1000)
			cost = 1000;
		else if(max_w > 100)
			cost = 100;

		cout<<cost<<" "<<max_w<<endl;
	return 0;
	}

	int main(){
		int T;
		cin>>T;
		while(T){
			calc();
			T--;
		}
		return 0;
	}