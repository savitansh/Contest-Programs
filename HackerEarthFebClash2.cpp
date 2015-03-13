#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long int> primes,lst;
vector<long long int>::iterator it,it2;

int prime[1000001];

int generate(){
	for(int i=2; i<=2000; i++){
		for(int j=2; i*j<=1000000; j++)
			prime[i*j] = 1;
	}
	for(int i=2; i<=1000000; i++){
		if(prime[i]==0)
			primes.push_back(i);
	}
}

int get(long long int l,long long int r){
	long long int n1 = 0, n2 = 0;
	int sz = primes.size();
	l--;
	for(int i=0; i<sz; i++){
		if(r >= primes[i]){
		it = lower_bound(primes.begin()+i+1,primes.end(),(r/primes[i]));
		if(((*it) * primes[i]) > r)
			it--;
		int z = it - (primes.begin()+i);
		if(z>0)
		n1 += z;
		 //cout<<primes[i]<<","<<*it<<","<<n1<<","<<endl;
		}
	}
	for(int i=0; i<sz; i++){
		if(l >= primes[i]){
		it2 = lower_bound(primes.begin()+i+1,primes.end(),(l/primes[i]));
		if(((*it2) * primes[i]) > l)
			it2--;
		int z = it2 - (primes.begin()+i);
		if(z>0)
		n2 += z;
		}
	}
	return (n1-n2);
}

int main(){
	generate();
	long long int l,r;
	int T;
	cin>>T;
	while(T){
		cin>>l>>r;
		cout<<get(l,r)<<endl;
		T--;
	}
}