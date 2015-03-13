#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

map<long long int,long long int> sqrRoot;

int calc(){
	long long int rsqr , k;
	cin>>rsqr>>k; 

	int xCount = 0,yCount = 0,integerRoots = 0;

	for (long long int x = 0; x*x <= rsqr; ++x)
	{
		long long int diff = rsqr - (x*x);
		if(sqrRoot.find(diff) != sqrRoot.end()){
			if(x >0)
				xCount = 2;
			else
				xCount = 1;

			long long int val = sqrRoot[diff];
	//		cout<<x<<":"<<val<<endl;
			if(val > 0)
				yCount = 2;
			else
				yCount = 1;
			integerRoots = integerRoots + xCount*yCount;
		}
	}
	//cout<<integerRoots<<endl;
	if(integerRoots > k)
		printf("impossible\n");
	else
		printf("possible\n");

	return 0;
}

int main(){
	for (long long int i = 0; i <= 70000; ++i)
	{
		long long int sqr = i*i;
		sqrRoot[sqr] = i;
	}
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}	
	return 0;
}