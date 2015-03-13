#include <iostream>
#include <map>
using namespace std;

map<long long int,int> M;
long long int arr[1000000];

int main(){
	int n,m,max1=-1,winner;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	for(int i=0; i<n; i++){
		M[arr[i]] =M[arr[i]] + 1;
		if(M.find(arr[i]) != M.end()){
			
			if(M[arr[i]] > max1){
			max1 = M[arr[i]];
			winner = arr[i];
			}else if(M[arr[i]] == max1){
			if(arr[i] > winner)
			winner = arr[i];
			}
		}
		cout<<winner<<" "<<max1<<endl;
	}
}