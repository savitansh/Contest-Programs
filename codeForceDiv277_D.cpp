#include <iostream>
#include <deque>
using namespace std;

deque<int> edge_list[3001];
deque<int>::iterator it,it2;

int add_to_q(int v1, int v2){
	edge_list[v1].push_back(v2);
}


int length(int v){
	return edge_list[v].size();
}
int count[100000];

int main(){
	int n,m,v1,v2,total=0;
	cin>>n>>m;
	for (int i = 0; i < m; ++i){
			cin>>v1>>v2;
			add_to_q(v1,v2);
		}	

	for (int i = 1; i <= n; ++i){
		int l = length(i);
		for(int r=1; r<=3000; r++)
			count[r]=0;

		for(it =edge_list[i].begin(); it != edge_list[i].end(); it++){
			int negh = *it;
			for(it2 = edge_list[negh].begin(); it2 != edge_list[negh].end(); it2++){
				int sec_negh = *it2;
				if(sec_negh != i)
				count[sec_negh]++;
			}
		}

		for(int k=1; k<=3000; k++){
		total = total + (count[k]*(count[k]-1))/2;
		}
		
	}

	cout<<total<<endl;
}