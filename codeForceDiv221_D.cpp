#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int counter[5000][5000];
int n_rows[5001];
int mat[5000][5000];
char bitstring[5000][5000];
	
int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		scanf("%s",bitstring[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			mat[i][j] = bitstring[i][j] - '0';
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == 1){
				if(j>=1)
				counter[i][j] = counter[i][j-1] +1;
				else
				counter[i][j] = 1;	
			}else
			counter[i][j] = 0;
		}
	}


	long long int ans = 0;
	for(int j=0; j<m; j++){
		for(int k =5001; k>=0; k--)
		n_rows[k] = 0;
		for(int i=0; i<n; i++){
			n_rows[counter[i][j]]++;
		}	
		long long int total_rows = 0;			// total no. of rows having k , k-1, k-2... continous 1s
		for(int k =5001; k>=0; k--){
			total_rows = total_rows + n_rows[k];
			ans = max(ans,total_rows*k);
		}
		}
	cout<<ans<<endl;
}