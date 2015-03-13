/* 
@author savitansh

Dynamic programming

T[i][Filled] means next hare is full and current is hungry
T[i][Hungry] means next hare is hungry and current is full 
*/

#include<iostream>
#define Filled 0
#define Hungry 1

using namespace std;

int main(){
	int n;
	int a[3001],b[3001],c[3001];

	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>b[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>c[i];
	}


	int T[3001][2];

	T[1][Filled] = b[1];
	T[1][Hungry] = a[1];

	for (int i = 2; i <= n; ++i)
	{
		T[i][Filled] = max(T[i-1][Hungry] + c[i] , T[i-1][Filled] + b[i]);
		T[i][Hungry] = max(T[i-1][Filled] + a[i] , T[i-1][Hungry] + b[i]);	
		
		//cout<<T[i][Filled]<<","<<T[i][Hungry]<<endl;
	}
	cout<<T[n][Hungry];

}