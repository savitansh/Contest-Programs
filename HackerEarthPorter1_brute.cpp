#include <iostream>
using namespace std;

int arr[100001];

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	while(q){
		int l,r,k;
		cin>>l>>r>>k;
		int j = l;
		long long int s = 0;
		while(j<=r){
			s += arr[j];
			j += k;
		}
		cout<<s<<endl;
		q--;
	}
	return 0;
}