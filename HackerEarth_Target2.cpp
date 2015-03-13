#include <iostream>
#define MOD 1000000007
using namespace std;


int main(){
	long long int a[100000] , old;
	int n;
	cin>>n;

	long long int prod = 1;
	int zeroCount = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		if(a[i] != 0)
		prod = ( prod * a[i] ) % MOD;
		else
			zeroCount++;
	}
	
	int q,c,id,v;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>c;
		if(c == 0){
			cin>>id>>v;
			old = a[id];
			a[id] = v;
			if(old == 0 && v != 0)
				zeroCount--;
			else if(old != 0 && v == 0)
				zeroCount++;

			if(old > 0 && v > 0)
			prod = ( ( prod / old ) * v )% MOD;
			else if(old == 0 && v > 0)
				prod = (  prod  * v )% MOD;
			else if(old > 0 && v == 0)
				prod = (prod / old) % MOD;

		}
		else{
			cin>>id;
			if(a[id] == 0 && zeroCount == 1){
				cout<<prod<<endl;
			}else if(zeroCount >= 1){
				cout<<0<<endl;
			}else if(zeroCount == 0)
			cout<<(prod / a[id])<<endl;
		}
	}
}