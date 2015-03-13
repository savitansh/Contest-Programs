#include <iostream>
#define MOD 1000000007
using namespace std;

long long int find_power(long long int x,long long int n){
	if(n == 0)
		return 1;
	else if(n == 1)
		return x;
	if(n % 2 == 0)
		return find_power((x*x % MOD), n/2) % MOD;
	return ((x % MOD)*find_power((x*x % MOD), (n-1)/2)) % MOD;
}

int calc(){
	long long int n;
	cin>>n;

	long long int initial_len = 4;

	long long int factor = 2*(find_power(2,n) - 1) % MOD;
	initial_len = (initial_len + factor) % MOD;

	cout<<initial_len<<endl;
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