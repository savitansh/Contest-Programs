#include <iostream>
#include <algorithm>
using namespace std;

int M[100][100],a[1000];
int n=0;
	
int fun(int i, int j){
	if(i>j)
		return 0;

	if(i==j)
		return M[i][j];

	if(M[i][j] != 0)
		return M[i][j];

	if(i+1<n && i+1>=0 && j-1<n && j-1>=0)
	{
		int val = fun(i+1,j-1);
		if(val != 0)
	M[i][j] = max(a[i]*val , a[j] * val);	
	}
	return M[i][j];

}
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++)
		M[i][i] = a[i];
	//fun(0,n-1);
	for(int i=0; i+1<n; i++){
		M[i][i+1] = a[i]*a[i+1];
	}
	
	int t = 2;
	int j = 0;
	while(j+t<n){
		while(j+t<n){
			int l = j + t; 
			M[j][l] =  max(a[j]*M[j+1][l-1] , a[l] * M[j+1][l-1]);
			cout<<M[j][l]<<" ";
			j++;
		}
		cout<<endl;
		t++;
		j = 0;
	}		
	cout<<M[0][n-1]<<endl;
}