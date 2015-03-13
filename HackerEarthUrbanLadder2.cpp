#include <iostream>
#include <map>
#define MAX1 1000000
using namespace std;

map<string, int> node_idx;
int dis[101][101];
	
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string station;
		cin>>station;
		node_idx[station] = i;
	}		
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i!=j)
				dis[i][j] = dis[j][i] = MAX1;

	for(int i=0; i<m; i++){
		string st1,st2;
		int dist;
		cin>>st1>>st2>>dist;
		dis[node_idx[st1]][node_idx[st2]] = dist;
		dis[node_idx[st2]][node_idx[st1]] = dist;
	}
	
	for(int k=0; k<n; k++)
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			{
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					dis[j][i] = dis[i][k] + dis[k][j];	
				}
			}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++)
	// 		cout<<dis[i][j]<<",";
	// 	cout<<endl;
	// }		

	int q;
	cin>>q;
	
	for(int i=0; i<q; i++){
		string st1,end1;
		cin>>st1>>end1;
		cout<<dis[node_idx[st1]][node_idx[end1]]<<endl;
	}	
	return 0;
}