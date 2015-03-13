/*
@author savitansh
n = a*b*c*d..
find s = (a + b + c + ..) such that s is min
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<long long int, std::vector<long long int>, std::greater<long long int> > my_min_heap;

int factors[100000];

int calc(){

	int n;
	long long int k=0;
	cin>>n>>k;

	int j=0;
	long long int tmp = k;
	for (int i = 2; i*i <= k; ++i)
	{
		if(tmp % i == 0 ){
			while(tmp%i==0){
				 tmp = tmp/i;
				 factors[j++] = -i;
			}
		}
	}
	if(tmp > 1)
	factors[j++] = -tmp;

	sort(factors,factors+j);

	for (int i = 0; i < j; ++i)
	{
		factors[i] = -factors[i];
	}

	for (int i = 0; i < n; ++i)
	{
		my_min_heap.push(1);
	}

	for (int i = 0; i < j; ++i)
	{
		long long int val = my_min_heap.top();
		my_min_heap.pop();
		my_min_heap.push(factors[i] * val);
	}

	long long int s = 0;
	for (int i = 0; i < n; ++i)
	{
		s = s + (my_min_heap.top());
		my_min_heap.pop();
	}
	cout<<s<<endl;

	for (int i = 0; i < j; ++i)
	{
		factors[i] = 0;
	}
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