#include <iostream>
using namespace std;

	int idx[100001],arr[100001];

int main(){
	int N;
	cin>>N;
	long long int K;
	cin>>K;
	for(int i=0; i<N; i++){
		cin>>arr[i];
		idx[arr[i]] = i;
	}
	int i=0;
	for(int j=N; j>=1; j--){
		if(idx[j] != i){
			int t = arr[i];
			arr[i] = j;
			arr[idx[j]] = t;
			idx[t] = idx[j];
			idx[j] = i;
			K--;
		}
		if(K==0)
			break;
		i++;

	}
	for(int i=0; i<N; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}