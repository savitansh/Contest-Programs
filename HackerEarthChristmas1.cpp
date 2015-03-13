#include <iostream>
#include <math.h>
#define PI 3.141593
using namespace std;

int calc(){
	double a,H,theta,h;
	cin>>a>>H>>theta;
	int ans = 0;

	double val = tan((theta * PI) / 180.0);
	
	if(H/val < a){
		ans = ceil(0.5*(H)*(H/val) / (a));
	}else{
	h = H - a*val;
	ans = ceil(0.5*(h+H));
	
}
cout<<ans<<endl;
}

int main(){
	long long int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}