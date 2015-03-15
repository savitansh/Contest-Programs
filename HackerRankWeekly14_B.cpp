#include <iostream>
using namespace std;

long long int arr[300001];

int calc(){
	long long int N=0,k=0;
	cin>>N>>k;
	for(int i=1; i<=N; i++)
		arr[i] = 0;

	for(int i=1; i<=N; i++)
		cin>>arr[i];

	int j = 1;
	long long ans=0;
	for(int i=1; i<=N; i++){
		if(arr[i]>k){
			long long int d = (i-1) - j + 1;
			// cout<<d<<endl;
			ans += (d * (d+1)) / 2;
			while(arr[i]>k && i<=N)
				i++;
			j = i;
		}
	}
	if(arr[N]<=k && arr[j]<=k){
	long long int left = N - j + 1;
	// cout<<left<<endl;
	ans += (left * (left+1)) /2;
	}
	cout<<(N*(N+1)/2) - ans<<endl;
	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
}