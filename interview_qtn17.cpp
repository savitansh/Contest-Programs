/*
rotate matrix by 90d 
*/
#include <iostream>
using namespace std;

int main(){
int A[100][100];
int tmp[1000],tmp2[1000];
int n;
cin>>n;
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++)
		cin>>A[i][j];
}

int row_st = 0, col_st = 0, row_end = n-1, col_end = n-1;	

int t = 0;
for(int k=col_st+1; k<=col_end; k++){
		tmp[t] = A[row_st][k];
		t++;
	}

while(row_st<row_end && col_st<col_end){
	t = 0;
	for(int k=row_st+1; k<=row_end; k++)
	{	
		tmp2[t] = A[k][col_end];
		A[k][col_end] = tmp[t];
		tmp[t] = tmp2[t];
		t++;
	}
	t = 0;
	for(int k=col_end-1; k>=col_st; k--)
	{	
		tmp2[t] = A[row_end][k];
		A[row_end][k] = tmp[t];
		tmp[t] = tmp2[t];
		t++;
	}
	t = 0;
	for(int k=row_end-1; k>=row_st; k--){
		tmp2[t] = A[k][col_st];
		A[k][col_st] = tmp[t];
		tmp[t] = tmp2[t];
		t++;
	}
	t = 0;
	for(int k=col_st+1; k<=col_end; k++){
		tmp2[t] = A[row_st][k];
		A[row_st][k] =tmp[t];
		tmp[t] = tmp2[t];
		t++;
	}
	row_st++;
	row_end--;
	col_st++;
	col_end--;
	t = 0;
	for(int k=col_st+1; k<=col_end; k++){
		tmp[t] = A[row_st][k];
		t++;
	}
}	

for(int i=0; i<n; i++){
	for(int j=0; j<n; j++)
		cout<<A[i][j]<<" ";
	cout<<endl;
}
return 0;
}