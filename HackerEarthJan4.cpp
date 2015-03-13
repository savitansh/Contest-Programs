#include <iostream>
#include <algorithm>
using namespace std;

int F[30][30];
int n;
int f(int idx, int n1, int n0){
	
	if(n1 <= n0)
		return 0;
	if(n0 == 0)
		return 1;

	if(idx==n-1)
	{
		if(n1>n0)
			return 1;
		return 0;
	}
	
	if(F[n1][n0] > 0)
		return F[n1][n0];

	F[n1][n0] = f(idx+1,n1-1,n0) + f(idx+1,n1,n0-1);
	return F[n1][n0];
}

int main(){
	int T;
	n = 4;
		cout<<f(0,4,0);
		
	return 0;
}