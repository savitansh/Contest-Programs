#include <iostream>
#include <stdlib.h>
using namespace std;

int cost(int i, int j){
	j = j - '0';
	return abs(i-j);
}

string s;
int C=0,n=0;
 long long int F[400][500][300];

 long long int fun(int idx,int current_sum, int total_cost){

	if(total_cost > C)
		return 0;

	if(idx == n){
		if(current_sum % 3 == 0){
			return 1;
			}
		else
			return 0;
	}
	
	
	if(F[idx][current_sum][total_cost] >-1)
		return F[idx][current_sum][total_cost];
	
	int k = 0;
	
	if(idx == 0)
		k = 1;

	 long long int ans = 0;
	for(int j = k; j<=9; j++)
	ans += fun(idx+1, current_sum+j, total_cost + cost(j,s[idx]));
	
	F[idx][current_sum][total_cost] = ans;
	return ans;
}

int main(){
	cin>>s;
	cin>>C;
	n = s.length();
	for(int i=0; i<400; i++)
		for(int j=0; j<500; j++)
			for(int k=0; k<300; k++)
				F[i][j][k] = -1;

	cout<<fun(0,0,0)<<endl;
	return 0;
}
