#include <iostream>
using namespace std;

long long int arr[1000000],x;

int main(){
	int n,m;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cin>>m;
	for(int j=0; j<m; j++){
		cin>>x;
		for(int i=0; i<n; i++){
			if(arr[i] > x)
				arr[i] -= 1;
		}
	}
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}