/*
@author savitansh
*/
#include <iostream>
using namespace std;

int G[100][100];
int find_gcd(int a, int b){
	if(a==b)
		return a;

	if(a > b)
		return find_gcd(a-b,b);
	else
		return find_gcd(b,b-a);
}

int gcd(int a, int b){
	if(a==0||b==0)
		return 0;
	if(a==b){
		G[a][b] = a;
		G[b][a] = a;
	}

	if(G[a][b] > 0)
		return G[a][b];

	G[a][b] = find_gcd(a,b);
	G[b][a] = G[a][b];
	return G[a][b];
}

int main(){
	int T;
	cin>>T;
	while(T){

	int h,m,s;
	long long count=0,ct=0;
	cin>>h>>m>>s;
	for(int i=h; i<24; i++){
		if(i>h)
			m=0;
		for(int j=m; j<60; j++){
			if(j>m)
				s=0;
			for(int k=s; k<60; k++){
				if(gcd(i,gcd(j,k)) > 1)
					count++;
					
				ct++;
			}
		}
	}
	int g1 = find_gcd(count,ct-count);
	if(g1 > 1)
	{
		count = count / g1;
		ct = (ct - count) / g1;
	}
	cout<<count<<":"<<ct<<endl;
	T--;	
	}
}