#include <iostream>
#define MOD 1000000007
using namespace std;

 long int D[1004][1004];

int find(){
	int n,m;
	cin>>n>>m;

	D[1][1] = 1;

	for(int r = 1; r<=n; r++){
		for(int j=1; j<=n; j++){
			if(r==1 && j==1)
				continue;

			int k = r-j;
			if(j >= m*k && D[r-1][j-1]>=0 && D[r-1][j]>=0)
				D[r][j] =(D[r-1][j-1] +  D[r-1][j]) % MOD;
			else
				D[r][j] = D[r-1][j-1] % MOD;
		}
	}
	long long ans = 0;

// for(int i=1;i<=n;++i)
// 			ans=(ans+D[n][i])%MOD;
// 		if(n%2==0 && m==1)

	for(int j=1; j<=n; j++){
		if(j>n-j && D[n][j]>=0)
			ans =(ans + D[n][j]) % MOD;
	}
	cout<<ans<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T){
		for(int i=1; i<=1003; i++)
			for(int j=1; j<=1003; j++)
				D[i][j] = 0;

		find();
		T--;
	}		
	return 0;	
}