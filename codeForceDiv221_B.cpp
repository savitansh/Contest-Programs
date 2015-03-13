#include <iostream>
using namespace std;

long long int mat[101][101];
	
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int b,l,val;
		cin>>b>>l>>val;
		mat[b][l] = val;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mat[i][j] > 0){
				for(int k=1; k<=n; k++){
					if(mat[j][k] > mat[i][j]){
						mat[j][k] = mat[j][k] - mat[i][j];
						mat[i][k] = mat[i][k]+ mat[i][j];
						mat[i][j] = 0;

					}else if(mat[j][k] < mat[i][j] && mat[j][k]>0){
						mat[i][j] = mat[i][j] - mat[j][k];
						mat[i][k] = mat[i][k]+mat[j][k];
						mat[j][k] = 0;
					}else if(mat[j][k] == mat[i][j]){
						mat[j][k] = 0;
						mat[i][k] = mat[i][k] + mat[i][j];
						mat[i][j] = 0;
					}
				}
			}
		}
	}

	int s = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j)
			s = s + mat[i][j];
		}
	}
	cout<<s<<endl;
}