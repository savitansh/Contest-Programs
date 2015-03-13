#include <iostream>
using namespace std;

int add(int x, int y){
	int carry = 0;
	int t=1;
	int ans = 0;
	while(x>0 || y>0){
		int b1 = x&1;
		int b2=  y&1;
		if((b1^carry^b2) == 1){
			ans = ans | t;	
			if(b1 == 0 && b2 ==0)
				carry = 0;
		}
		else if(b1 ==1 || b2 == 1){
			carry = 1;
		}
		t = t*2;
		if(x>0)
		x = x>>1;
		if(y>0)
		y = y>>1;
	}
	if(carry == 1)
		ans = ans | t;
	return ans;
}

int main(){
	int ans = add(15,17);
	cout<<ans<<endl;
}