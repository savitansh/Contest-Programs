#include <iostream>
#define MAX1 100000000
using namespace std;

long long int F[1000001];

long long int find_min(long long int a,long long int b,long long int c,long long int d){
	long long int m = 100000000;
	if(a > 0)
		m = min(m,a);
	if(b > 0)
	m = min(m,b);
	if(c> 0)
	m = min(m,c);
	if(d> 0)
	m = min(m,d);
	return m;
}
int main(){
	F[1] = -1;
	F[2] = 1;
	F[3] = 1;
	F[4] = 2;
	F[5] = 1;
	F[6] = 2;
	F[7] = 1;

	for(int i=8; i<=1000000; i++){
		long long int z = find_min(F[i-2],F[i-3],F[i-5],F[i-7]);
		if(z < MAX1)
		F[i] = z + 1;
			
	}
	int T;
	cin>>T;
	while(T){
	int x;
	cin>>x;
	if(F[x] > 0)
	cout<<F[x]<<endl;
	else
	cout<<-1<<endl;	
	T--;
	}
}