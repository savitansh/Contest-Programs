#include <iostream>
#include <stdlib.h>
using namespace std;

	char s[100000];

	int count[30];

int calc(){
	
	int l,r;
	cin>>l>>r;
	for(int i=l-1; i<=r-1; i++){
		count[s[i]-'a'] ++;
	}
	if(abs(count['z'-'a'] - count['x'-'a']) > 1 || abs(count['z'-'a'] - count['y'-'a']) > 1 
		|| abs(count['x'-'a'] - count['y'-'a']) > 1 || count['x' - 'a'] == 0 || count['y'- 'a'] == 0 || count['z'- 'a'] == 0) 
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	for (int i = 0; i < 30; ++i)
	{
		count[i] = 0;
	}
}

int main(){
	int T;
	cin>>s;
	cin>>T;

	while(T){
		calc();
		T--;
	}
	return 0;
}