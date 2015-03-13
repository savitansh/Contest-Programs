#include <iostream>
using namespace std;

int calc(){
	long long int a,b;
	cin>>a>>b;
	if(a==b)
		return a;

	long long t = 2;
	long long z = 0;
	for(int j=1;j<32; j++){
		if((a/t == b/t) && ((a&t)!=0) && ((b&t)!=0))
			z = z | t;
		t = t<<1;
	}
	cout<<z<<endl;
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