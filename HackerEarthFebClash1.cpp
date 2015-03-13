#include <iostream>
#define MOD 1000000007
using namespace std;

long long int D[1000000];

int main(){
	int n,p,T;
	cin>>T;
	while(T){
	cin>>n>>p;
	D[0] = D[1] = 1;

	for(int i=1; i<=n; i++){
		for(int j=0; j<=p-1; j++)
			if(i>=j)
			D[i+1] += D[i-j] % MOD;
	}
	cout<<(D[n] % MOD)<<endl;

	for(int i=0; i<=n+1; i++)
		D[i] = 0;
	T--;
	}

}