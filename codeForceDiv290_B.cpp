#include <iostream>
using namespace std;

int main(){
	char M[50][50];
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>M[i][j];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int c = j;
			while(c<m && M[i][c] == M[i][j])
				c++;
			c--;
			r = i;
			while(r<n && M[r][j] == M[i][j])
				r++;
			r--;
			int l3=i,l4=j;
			bool flag = false;
			while(l3 <= c){
				if(M[r][l3] != M[i][l3]){
					flag = true;
					break;
					}
					l3++;
			}
			if(flag == false){
				while(l4 <= r){
					if(M[l4][j] != M[l4][c]){
						flag = true;
						break;
					}
					l4++;
				}
			}
			if(flag == false){
				cout<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}