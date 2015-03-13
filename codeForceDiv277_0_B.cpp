#include <iostream>
using namespace std;

int B[100][100],A[100][100];

int main(){
	int m,n;
	bool possible=false;
	cin>>m>>n;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>B[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(B[i][j] ==0){
				for(int k=0; k<n; k++){
					A[i][k] = -1;
				}
				for(int k=0; k<m; k++){
					A[k][j] = -1;
				}
			}
		}
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(B[i][j] == 1){
				possible = false;
				for(int k=0; k<n; k++){
					if(A[i][k] != -1){
						A[i][k] = 1;
						possible = true;
						break;
					}
				}
				if(possible == false){
					for(int k=0; k<m; k++){
						if(A[k][j] != -1){
							A[k][j] = 1;
							possible = true;
							break;
						}
					}
				}
				if(possible == false){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(A[i][j] == -1)
				A[i][j] = 0;
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}