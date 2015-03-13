#include <iostream>
using namespace std;

int a[1000],l[1000],r[1000];

int main(){
	int max1 = 0;
	int n=0;
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++){
		if(a[i] > max1){
			max1 = a[i];
			l[i] = max1;
		}
		else
			l[i] = l[i-1];
	}
	max1 = 0;

	for(int i=n-1; i>=0; i--){
		if(a[i] > max1){
			max1 = a[i];
			r[i] = max1;
		}
		else
			r[i] = r[i+1];
	}
	/*
	for(int i=0; i<n; i++){
		cout<<l[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<r[i]<<" ";
	}
	*/
	int total = 0;

	for(int i=0; i<n; i++){
		if(a[i] < l[i] && a[i] < r[i]){
			total += (min(l[i],r[i]) - a[i]);
		}
	}
	cout<<total<<endl;
}