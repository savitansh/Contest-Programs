#include <iostream>
using namespace std;

int main(){
	int rows[100],cols[100];
	int n;
	for (int i = 0; i < n; ++i)
	{
		int r,c;
		cin>>r>>c;
		rows[r] = c;
		cols[c] = r;
	}

	int m = n-1;
	for (int i = 1; i <= n; ++i)
	{
		if(cols[m] != 0){
			for(int r=1; r<=m-1; r++){
				if(cols[r] == 0){
					toSwap = r;
					break;
				}
			}
			tmp = cols[m];
		cols[m] = 0;
		cols[toSwap] = tmp;
		rows[m] = 
		}
		if(rows[m] == 0){
		for(int j=1; j<=m-1; j++){
				if(rows[j] != 0){
					toSwap = j;
					break;
				}
			}
			tmp = rows[m];
		rows[m] = 0;
		rows[toSwap] = tmp;	
		}
		m--;
	}
}