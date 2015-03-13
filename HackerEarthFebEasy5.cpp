#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[100000];

int calc(){
	int n,k;
	bool flag = true;
	long long p;
	cin>>n>>k>>p;
	
	for(int i=0; i<100000; i++)
		arr[i] = 0;
	
	for(int i=0; i<n; i++)
	cin>>arr[i];

	sort(arr,arr+n);
	for(int i=0; i<=n-k; i++){
		if(arr[i+k-1] <= arr[i] + 2*p){
			flag = false;
		}
	}
	if(flag == false)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
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