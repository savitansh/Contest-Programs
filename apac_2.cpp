#include <iostream>
using namespace std;

int count[501];
int start[51],end[51];
		
int calc(int t){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>start[i]>>end[i];
	}
	for(int i = 0; i<n; i++){
		for(int j = start[i]; j<=end[i]; j++){
			count[j]++;
		}
	}
	int p,city[51];
	cin>>p;
	for(int i=0; i<p; i++){
		cin>>city[i];
	}

	cout<<"Case #"<<t<<":";
	for(int i=0; i<p; i++){
		cout<<" "<<count[city[i]];
	}
	cout<<endl;

	for(int i=0; i<501; i++)
		count[i] = 0;
	for(int i=0; i<50; i++){
		start[i] = 0;
		end[i] = 0;
	}
}

int main(){
	int T;
	cin>>T;
	int t = 1;
	while(t<=T){
		calc(t);
		t++;
	}
	return 0;
}