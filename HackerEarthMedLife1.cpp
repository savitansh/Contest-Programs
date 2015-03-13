#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T){
	int a,b;
	cin>>a>>b;
	
	long long int s = 0;
	if(a >5)
	{
		s = s + (b-a+1)*9;
	}else{
		int m = min(b,5);
	for(int i=a; i<=m; i++){
		if(i == 1)
		s = s + 1;
		else if(i==2)
		s = s + 2;
		else if(i==3)
		s = s+6;
		else if(i==4)
		s = s+6;
		else if(i==5)
		s = s+3;
	}
	if(b > 5)
		s = s + (b-5)*9;
	}

	cout<<s<<endl;
	T--;
	}
}