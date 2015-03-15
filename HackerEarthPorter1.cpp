#include <iostream>
using namespace std;

long int cumm[11][100001];
long int arr[100001];

int main(){
	int n,k,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	for(int k=1;k<=10; k++){
		int j=2;
		cumm[k][1] = arr[1];
		while(j<=n){
			if((j-1) % k == 0)
				cumm[k][j] = cumm[k][j-1] + arr[j];
			else
				cumm[k][j] = cumm[k][j-1];
			j++;
		}
		for(int i=1;i<=n; i++)
			cout<<cumm[k][i]<<" ";
		cout<<endl;
	}

	while(q){
		int l,r;
		cin>>l>>r>>k;
		if(l>1)
			cout<<(cumm[k][r] - cumm[k][l-1])<<endl;
		else
			cout<<(cumm[k][r])<<endl;
	}
}