/*
@author savitansh
segment trees
*/
#include <iostream>
#define MOD 1000000007
using namespace std;

int tree[100000];
int cumSum[100000];

int createTree(int l , int r , int node){

	if(r < l)
		return 0;

	if(r == l)
	{
		tree[node] = cumSum[r] - cumSum[r-1];
		return 0;
	}
	int mid = (l + r) / 2;

	tree[node] = cumSum[r] - cumSum[l-1];
	createTree(l , mid , 2*node);
	createTree(mid+1,r,2*node+1);

	return 0;
}

int getSum(int l , int r , int u , int v, int node){
	if(r < l)
		return 0;
	
	if(r<u || l>v)
		return 0;

	if( u <= l && r <= v){
		return tree[node];
	}

	int mid = (l+r)/2;
	return getSum(l , mid , u , v , 2*node) + getSum(mid+1, r , u , v , 2*node + 1);
}

int updateTree( int l, int r, int u, int v , int node){

	if(r < l)
		return 0;

	if(r == l)
	{
		tree[node] = cumSum[r] - cumSum[r-1];
		return 0;
	}
	int mid = (l + r) / 2;

	tree[node] = cumSum[r] - cumSum[l-1];
	createTree(l , mid , 2*node);
	createTree(mid+1,r,2*node+1);
	return 0;

}

int main(){

	int n;
	long long int val=0;
	cin>>n;
	cin>>val;
	cumSum[1] = val;
	for(int i=2; i<=n; i++){
		cin>>val;
		cumSum[i] = (cumSum[i-1] + val) % MOD;
	}

	createTree(1,n,1);

	for (int i = 1; i <= n; ++i)
	{
		cout<<tree[i]<<" ";
	}
	
	cout<<endl;
	
	int q , choice , l , u;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>choice>>l>>u;
		if(choice == 1)
			cout<<getSum(1,n,l,u,1)<<endl;
		else{
			int v=2;
			int sum1 = 0;
			cumSum[l] = cumSum[l] + v;
			for(int i=l+1; i<=u; i++){
				sum1 = (sum1 + v) % MOD;
				v = v*2 % MOD;
				cumSum[i] = (cumSum[i] + sum1 + v) % MOD;
			}
			for(int i=u+1; i<=n; i++){
				cumSum[i] = (cumSum[i] + sum1) % MOD;
			}
			updateTree(1,n,l,n,1);
					
		}
			
	}
	
}