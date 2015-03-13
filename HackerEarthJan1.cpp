#include <iostream>
#include <algorithm>
using namespace std;

int g[10000],b[10000];

int calc(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		b[i] = g[i] = 0;
	}
	
	for(int i=0; i<n; i++)
		cin>>g[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		b[i] = -b[i];


	sort(g,g+n);
	sort(b,b+n);

	for(int i=0; i<n; i++)
		b[i] = -b[i];

	int count = 0;
	for(int i=0; i<n; i++){
		if(b[i]%g[i] == 0 || g[i]%b[i]==0)
			count++;
	}
	cout<<count<<endl;
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