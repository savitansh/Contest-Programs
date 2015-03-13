#include <iostream>
using namespace std;

int calc(){
	 unsigned  n;
	cin>>n;
	   unsigned m = (2<<31) - 1;
	cout<<(n^m)<<endl;
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