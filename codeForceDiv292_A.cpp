#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	long long int a=0,b=0,s=0;
	cin>>a>>b>>s;
	long long int d1 = abs(a)+abs(b);
	if(s>d1){
		s = s - d1;
		if(s%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}else if(s<d1)
	cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}