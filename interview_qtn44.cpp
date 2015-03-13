/*
count no of set bits in 1-n
*/
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	n++;
	int t = 2,ans = 0;
	while(t < n){
		int val = (n-1)%t;
		ans = ans + (n/t) * (t/2);
		 if(val+1 > t/2)
		 	ans += (val+1) - t/2;

		t = t*2;
	}
	ans = ans + (n+1)%(t/2);
	cout<<ans<<endl;
}
