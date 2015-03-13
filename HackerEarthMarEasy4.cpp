/*
@author savitansh
*/
#include <iostream>
#include <stdio.h>
using namespace std;

long int D[1000001],ans[1000001];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int l,r;
		scanf("%d",&l);
		scanf("%d",&r);
		D[l]++;
		D[r+1]--;
	}
	for(int i=1; i<=n+1; i++)
		D[i] += D[i-1];

	for(int i=1; i<=n+1; i++)
		ans[D[i]]++;
	// for(int i=1; i<10; i++)
	// 	cout<<ans[i]<<",";

	for(int i=n+1; i>=1; i--){
		ans[i] += ans[i+1];
//		cout<<i<<":"<<ans[i]<<endl;
	}

	int q;
	cin>>q;
	while(q){
	int k;
	scanf("%d",&k);
	printf("%d\n",ans[k]);
	q--;	
	}
	return 0;
}