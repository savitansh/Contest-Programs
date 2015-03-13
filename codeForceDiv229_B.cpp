/*
@author savitansh
*/
#include <iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	int a[100000],b[100000];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
	}
	long long int total_joy = 0;
	for(int i=0; i<n; i++){
		if( b[i] < 2 || 2*a[i] < b[i])
			total_joy -= 1;
		else{
			long long int v1 = b[i]/2;
			long long int v2 = b[i] - (b[i]/2);
			v1 = v1 * v2;
		total_joy += v1;
		} 
	}	
	cout<<total_joy<<endl;
}