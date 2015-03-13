/*
@author savitansh
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int getXor(int a , int b){
	return abs(a-b);
}

char str1[2000000];
int bits[2000000],decoded[1000000];
	
int main(){
	int n,k;
	cin>>n>>k;
	cin>>str1;

	for(int i=1; i<=n+k; i++){
		bits[i] = str1[i-1] - '0';
	}
	int j = 1;
	decoded[1] = bits[1];
	for(int i=2; i<=n; i++){
		if(i<=k){
			decoded[i] = getXor(bits[i-1] , bits[i]);
		}else{
			decoded[i] = getXor(bits[i] , getXor(decoded[j] , bits[i-1]));
			j++;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<decoded[i];
	}
	cout<<endl;

	return 0;
}