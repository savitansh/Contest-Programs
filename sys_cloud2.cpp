#include <iostream>
using namespace std;

int calc(){
	long long int a,b;
	cin>>a>>b;

	if(b % 2 == 0)
		b--;
	long long ans = 0;
	if(b-1 <= a)
		ans = a&(a+1);
	else
	 ans = b & (b-1);
	cout<<ans<<endl;
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