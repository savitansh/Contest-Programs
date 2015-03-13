/*
@author savitansh
*/
#include <iostream>
using namespace std;

int main(){
	int a[100000];
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}	
		int i=0;
	while(i<n){
		if(a[i] == 1){
			if(i+1<n)
				cout<<"PR";
			else
				cout<<"P";	
			a[i]--;
			i++;
		}	
		if(a[i] > 1){
			if(i+1<n)
			cout<<"PRL";
			else
			cout<<"PLR";	
			a[i]--;
		}
		if(a[i] ==0){
			if(i+1<n)
			cout<<"R";
			i++;
		}

	}	
	cout<<endl;
}