#include <iostream>
#include <vector>
#include <map>
#define MIN1 10000000
using namespace std;

vector<int> edge_list[100001];
char color[100001],gender[100001];
map<char,char> complement;

bool flag = true;	
int assign(char c, int node){
	color[node] = c;
	int sz = edge_list[node].size();

	for(int i=0; i<sz; i++){
		if(color[edge_list[node][i]] == color[node]){
			flag = false;
			return -1;
		}
		else if(color[edge_list[node][i]] == 0)
			assign(complement[c],edge_list[node][i]);
	}
	return 0;
}

int count_inversions(int n){
	int count = 0;
	for(int i=0; i<n; i++)
		if((gender[i]=='B' && color[i]=='p') || (gender[i]=='G' && color[i]=='b'))
			count++;
	return count;	
}

int main(){
	int n,e;
	cin>>n>>e;
	complement['b'] = 'p';
	complement['p'] = 'b';

	for(int i=0; i<n; i++)
		cin>>gender[i];

	for(int i=0; i<e; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		edge_list[a].push_back(b);
		edge_list[b].push_back(a);
	}
	
	int m1 = MIN1;
	assign('b',0);
	if(flag == true){
		m1 = count_inversions(n);
	}
	flag = true;
	for(int i=0; i<n; i++)
		color[i] = 0;
	
	assign('p',0);
	if(flag ==true){
		m1 = min(m1,count_inversions(n));
	}
	if(m1 != MIN1)
		cout<<m1<<endl;
	else
		cout<<"Not possible"<<endl;
}