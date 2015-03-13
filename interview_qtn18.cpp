/*
find maximum submatrix sorted row-wise and column-wise
*/
#include <iostream>
using namespace std;


	int A[100][100];
	int L[100][100];

int main(){
	int n = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>A[i][j];
	}

for(int i=0; i<n; i++){
	for(int j=1; j<n; j++){
		if(A[i][j] > A[i][j-1])
		L[i][j] = L[i][j-1] + 1;
		else
		L[i][j] = 0;	
	}
}	
int max_prod = 0,max_stR=0,max_endR=0,max_endC=0,min_stC=0,start=0,end=0;
int prod = 0;
int min_L = 0;

	for(int j=0; j<n; j++){
		start = 0;
		end = 0;
		for(int i=0; i<n; i++){
			if(i>=1 && A[i][j] >= A[i-1][j]){
			end++;
			min_L = min(min_L, L[i][j]);
			}else{
				start = i;
				end = i;
				min_L = L[i][j];
			}
			prod = (end - start + 1) * min_L;
			cout<<prod<<" ";
			if(prod > max_prod){
				max_stR= start;
				max_endR = end;
				max_endC = j;
				min_stC = j - min_L;
		}
		cout<<endl;
	}
}
	for(int i=max_stR; i<=max_endR; i++){
		for(int j=min_stC; j<=max_endC ; j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	} 
}