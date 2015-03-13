#include <iostream>
using namespace std;

long long int arr[1000000];

int main(){
	int n=0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	long long int b = arr[0];
	long long int diff = arr[1] - arr[0];

	for(int i=1; i<n-1; i++){
		if(arr[i+1]-arr[i] != diff){
			cout<<"impossible"<<endl;
			return 0;
		}
	}
	cout<<b<<" "<<diff<<endl;
	return 0;
}