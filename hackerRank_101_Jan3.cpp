#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long int sum[1000000];
vector<long long> vec;

int main(){
	int n;
	cin>>n;
	long long val;

	for(int i=1; i<=n; i++){
		scanf("%lld",&val);
		vec.push_back(val);
	}
	
	sort(vec.begin(),vec.end());
	
	int sz = vec.size();
	for(int i=0; i<sz; i++){
		sum[i+1] = sum[i] + vec[i];
	}
	
	int q;
	long long prev=0,x;
	cin>>q;
	while(q){
	scanf("%lld",&x);
	prev += x;
	vector<long long int>::iterator pos_it = lower_bound(vec.begin(),vec.end(),-prev);
	int idx = pos_it - vec.begin();
	long long val = sum[n] - sum[idx] + prev*(n - idx);
	//cout<<val<<endl;
	val += -sum[idx] - prev*idx;
	//cout<<val<<endl;
	
	printf("%lld\n",val);
	q--;
	}
}