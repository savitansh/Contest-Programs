#include<iostream>
#include<map>
using namespace std;

std::map<long long, long long> nos;

long long int arr[100001];
	
int calc(){
	int N,xored = 0;
	cin>>N;
	for (int i = 1; i <= N; ++i)
	{
		cin>>arr[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int len1 = N - i;
		int len2 = i - 1;
		int s = (N*(N+1)) / 2 - (len1*(len1+1))/2 - (len2*(len2+1))/2;
		nos[arr[i]] = nos[arr[i]] + s; 
	}

	for (int i = 1; i <= N; ++i)
	{
		if(nos[arr[i]] % 2 != 0)
			{
				xored = xored ^ arr[i];
				nos[arr[i]] = 0;
			}
	}

	cout<<xored<<endl;

	for (int i = 0; i < N; ++i)
	{
		nos[arr[i]] = 0;
		arr[i] = 0;
	}
	return 0;
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