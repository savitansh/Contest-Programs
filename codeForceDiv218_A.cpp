#include <iostream>
using namespace std;

int arr[100];
int mat[100][100];	
int count[3];
int main(){
	int n=0,k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int t=0,x=0;
	while(t<n){
		for(int l=0; l<k; l++){
			mat[x][l] = arr[t];
			t++;
		}
		x++;
	}

	// for(int m=0; m<x; m++){
	// 	for(int l=0; l<k; l++){
	// 		cout<<mat[m][l];
	// 	}
	// 	cout<<endl;
	// }

	int total = 0;

	for(int l=0; l<k; l++){
		count[1] = 0;
		count[2] = 0;
		for(int j=0;j<x;j++){
			count[mat[j][l]]++;
		}
		int val = min(count[1],count[2]);
		total += val;
	}

	cout<<total<<endl;

	return 0;
}