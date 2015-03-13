/*
You are given a String S that consists of characters '0' and '1' only. 
S represents the string given to a player of the Turing game. 
Return the smallest positive integer K such that it is possible to cut S into K pieces, 
each of them being a power of 5. If there is no such K, return -1 instead.
*/
#include <iostream>
#include <string>
using namespace std;
string str1;

  int P[1000000];
int M[1000][1000];

int make_powers(){
	long long int v = 1;
	for(int i=0; i<1000000; i++){
		P[i] = v;
		v = v*5;
	}
}

bool find_match(int val){
	int i=0;
	while(P[i]<=val){
		if(P[i]==val)
			return true;
		i++;
	}
	return false;
}

bool check(int i, int j){
	int t = 1;
	int val = 0;
	for(int k=i; k<=j; k++)
	{
		if(str1[k]=='1')
		val = val + t;
		t = t*2;
	}
	
	if(find_match(val))
		return true;
	return false;
}

int eval(int i, int j)
{
	if(i==j){
	if(str1[i]=='1')
		M[i][i]=1;
	else
		M[i][i] = -1;
	return M[i][i];		
	}
		
	if(M[i][j]==0){
		//cout<<M[i][j]<<":"<<i<<":"<<j<<endl;
		//return 1;
	if(check(i,j)){
		M[i][j] = 1;	
		//cout<<M[i][j]<<":"<<i<<":"<<j<<endl;
		return M[i][j];
	}
	else
	{
		int min1 = 10000;
		for(int k=i; k<j;k++){
			if(M[i][k]==0)
					eval(i,k);
				if(M[k+1][j]==0)
					eval(k+1,j);
			if(M[i][k]>0 && M[k+1][j]>0){
				if(M[i][k] + M[k+1][j] < min1)
					min1 = M[i][k] + M[k+1][j];
			}
		}
		if(min1 < 10000)
			M[i][j] = min1;
		else
			M[i][j] = -1;
	//	cout<<i<<":"<<j<<","<<M[i][j]<<endl;
	}
	//cout<<i<<":"<<j;
	return M[i][j];
	}
}

int main(){
	make_powers();
	cin>>str1;
	int n = str1.length();
	cout<<eval(0,n-1);
		
}