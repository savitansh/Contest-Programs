/*
@author savitansh
find sum of digits of factorial of N
*/
#include <iostream>
using namespace std;

int factorial[3000][1001];
int l = 3000;

int find_fact(int n, int l, int N){

	int digit = 0,carry = 0;
	for (int i = 0; i < l; ++i)
	{
		factorial[i][N] = factorial[i][N-1];
	}

	for (int i = 0; i < l; ++i){

		int s = factorial[i][N] * n + carry;
		digit = s % 10;
		carry = s/10;
		factorial[i][N] = digit;
	}
}

int calc(){
	for (int i = 0; i <= 1000; ++i)
	{
		factorial[0][i] = 1;
	}

	for (int j = 1; j <= 1000; ++j){
	find_fact(j,3000, j);
	}
	
return 0;	
}

int find_sum(int n){
	int s = 0;
	for (int i = 0; i < l; ++i)
	{
		s = s + factorial[i][n];
	}
	cout<<s<<endl;	
	
}

int main(){
	int T;
	cin>>T;
	calc();
	while(T){
		int N;
		cin>>N;
		find_sum(N);
		T--;
	}
	return 0;
}