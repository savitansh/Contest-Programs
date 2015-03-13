#include <iostream>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007
using namespace std;

int distinctDigits(int val){
	int digs[10];
	memset(digs,0,20);
	int digCount = 0;
	while(val > 0){
	int d = val % 10;
	if(digs[d] == 0)
	{
		digs[d] = 1;
		digCount++;
	}
	val = val / 10;
}
return digCount;
}

int main(){
	long long int arr[100000];
	int dis[100000];
	int n,maxDigits = 0,minDigits=12;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		int distinct = distinctDigits(arr[i]);
		dis[i] = distinct;
		if(dis[i] > maxDigits){
			maxDigits = dis[i];
		}
		if(dis[i] < minDigits){
			minDigits = dis[i];
		}
	}
	
	int q;
	long long int u,v,val;
	char op[3];

	cin>>q;
	for(int i=0; i<q; i++){
		cin>>op;
		cin>>u>>v;
		if(strcmp(op,"ADD") == 0){

			u--;
			val = arr[u];
			val = (val + v) % MOD;
			int distinct = distinctDigits(val);
			dis[u] = distinct;
			if(distinct > maxDigits)
				maxDigits = distinct;
			if(distinct < minDigits)
				minDigits = distinct;

		}	else if(strcmp(op,"MUL") == 0){

			u--;
			val = arr[u];
			val = (val * v) % MOD;
			int distinct = distinctDigits(val);
			dis[u] = distinct;
			if(distinct > maxDigits)
				maxDigits = distinct;
			if(distinct < minDigits)
				minDigits = distinct;

		}	else if(strcmp(op,"REP") == 0){

			u--;
			arr[u] = v;
			val = v;
			int distinct = distinctDigits(val);
			dis[u] = distinct;
			if(distinct > maxDigits)
				maxDigits = distinct;
			if(distinct < minDigits)
				minDigits = distinct;

		}
		else if(strcmp(op,"MAX") == 0){

			u--; 
			v--;
			int maxCount = 0;
			for(int i=u; i<=v; i++){
				if(dis[i] == maxDigits){
					maxCount++;
				}
			}
			cout<<maxDigits<<" "<<maxCount<<endl;

		}else if(strcmp(op,"MIN") == 0){
			
			u--; 
			v--;
			int minCount = 0;
			for(int i=u; i<=v; i++){
				if(dis[i] == minDigits){
					minCount++;
				}
			}
			cout<<minDigits<<" "<<minCount<<endl;

		}

	}
	

}