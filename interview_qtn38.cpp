/*
permutations of an array
*/
#include <iostream>
using namespace std;

int N;

int swap(int arr[100],int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int permute(int arr[100],int n){
	if(n == N){
		return 0;
	}

	for(int i=n-1; i>=0; i--){
		swap(arr,i,n);
		for(int j=0; j<N; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		permute(arr,n+1);
		swap(arr,i,n);
		
	}
}

int main(){
	int arr[100];
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>arr[i];


	permute(arr,1);
}