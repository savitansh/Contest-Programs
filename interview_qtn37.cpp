/*
remove duplicates from sorted array
*/
#include <iostream>
using namespace std;

int a[10000];

int swap(int p1, int p2){
	int t = a[p1];
	a[p1] = a[p2];
   a[p2] = t; 
}

int main(){

	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];

	int p1 = 1, p2 = 1;
	int current = a[0];

	while(p2 < n){
		if(a[p2] == current){
			p2++;
		}
		else{
			current = a[p2];
			swap(p1,p2);
			p1++;
			p2++;
		}
	}

	for(int i=0; i<p1; i++)
	cout<<a[i]<<" ";	
}