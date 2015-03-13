#include <iostream>
using namespace std;

int main(){
	int arr[1000],max_sum[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	max_sum[0] = arr[0];
	max_sum[1] = max(arr[0],arr[1]);

	for(int i=2; i<n; i++){
		max_sum[i] = max(max_sum[i-2]+arr[i], max_sum[i-1]);
	}
	
	cout<<max_sum[n-1]<<endl;
}