/*
@author savitansh
*/
#include <iostream>
using namespace std;

int calc(){
	int n,p1,p2,poss,t;
	cin>>n>>p1;
	p2 = p1;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin>>c;
		if(c == 'P'){
			p1 = p2;
			cin>>p2;
			poss = p2;
		}	else if(c == 'B'){
			poss = p1;
			t = p2;
			p2 = p1;
			p1 = t;
		}
		//cout<<poss<<endl;
	}
	cout<<"Player "<<poss<<endl;
	return 0;
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