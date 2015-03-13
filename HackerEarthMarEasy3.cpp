#include <iostream>
using namespace std;

int primes[1000000];

int generate(){
	primes[0] = primes[1] = 1;
	for(int i=2; i<=1000; i++){
		for(int j=2; i*j<=1000000; j++){
			primes[i*j] = 1;
		}
	}
}

int gcd(int x, int y){
	if(x==y)
		return x;
	if(x>y)
		return gcd(x-y,y);
	return gcd(x,y-x);
}

int calc(){
	int n,count = 0;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		if(gcd(i,n)==1)
			count++;
	}
//	cout<<count<<endl;
	if(primes[count]==0)
		cout<<"TRUE";
	else
		cout<<"FALSE";
	cout<<endl;
}

int main(){
	generate();
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
}