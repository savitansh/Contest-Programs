/*
union of overlapping intervals
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct range{
	int start;
	int end;
}r[1000];

bool comp(const range &a, const range &b){
	if(a.start < b.start)
		return 1;
	return 0;
}

int L[1000];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>r[i].start;
		cin>>r[i].end;
	}	
	sort(r,r+n,comp);
	for(int i=0; i<n; i++)
	cout<<r[i].start<<","<<r[i].end<<endl;

	int t=0;
	for(int k=r[0].start; k<=r[0].end; k++)
		L[k] = 1;
	for(int i=1; i<n; i++){
		if(r[i-1].end >= r[i].start && r[i-1].start < r[i].start){
			for(int k=r[i-1].end; k<=r[i].end; k++)
				L[k] = 1;
		}else if(r[i-1].end < r[i].start){
			for(int k=r[i].start; k<=r[i].end; k++)
				L[k] = 1;
		}
	}
	for(int i=0; i<100; i++)
		cout<<L[i];
	cout<<endl;
}