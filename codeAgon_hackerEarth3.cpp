#include <iostream>
using namespace std;

int N,p;
int sum[1000],pac[1000];
int F[1000][1000];

int cost(int start, int end, int n){

	if(start == end){
		return sum[end] - sum[start-1];
	}
	if(n == 0)
	{
		return sum[end] - sum[start-1];
	}

	int v1,v2;
	int v3 = 1000000;
	if(F[start][end] > 0)
		return F[start][end];

	for(int i=start; i<end; i++){
		if(start>=1)
		v1 = sum[i] - sum[start-1];
		else
		v1 = sum[i];	
		v2 = cost(i+1,end,n-1);
		v3 = min(v3,max(v1,v2));
	}
	F[start][end] = v3;
	return v3;
}

int main(){
cin>>N;
cin>>p;

for(int i=0; i<p; i++)
cin>>pac[i];

sum[0] = pac[0];
for(int i=1; i<p; i++){
	sum[i] = sum[i-1] + pac[i];
}

cout<<cost(0,p-1,N-1)<<endl;
}