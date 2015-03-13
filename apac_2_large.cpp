#include <iostream>
#include <algorithm>
using namespace std;

int count[501];

struct data{
int start,end;	
}data1[100000];

bool comparePairs(const struct data &lhs, const struct data &rhs)
{
  return lhs.start < rhs.start;
}		

int countVec[10000];

int calc(int t){
	int n,strt,en;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>strt>>en;
		data1[i].start = strt;
		data1[i].end = en;
	}
	sort(data1,data1+n,comparePairs);

	for(int i=0; i<n; i++){
		for(int j=data1[i].start; j<=data1[i].end; j++){
			countVec[j] += 1;
		}
	}
	int p,city[5001];
	cin>>p;
	for(int i=0; i<p; i++){
		cin>>city[i];
	}

	cout<<"Case #"<<t<<":";
	for(int i=0; i<p; i++){
		cout<<" "<<countVec[city[i]];
	}
	cout<<endl;
	for(int i=0; i<5001; i++)
		countVec[i] = 0;
	for(int i=0; i<500; i++){
		data1[i].start = 0;
		data1[i].end = 0;
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