#include <iostream>
#include <stdlib.h>
using namespace std;

long long int arr[1000000];
long long int sum[1000000];

int pre(int n){
	int i=0;
	if(n==1)
		return 1;
	if(sum[n] > 0)
		return sum[n];

	
	long long int p1 =0,p2 = n;
	
	p1 = n/2;
	int c = n/2;
	while(c>0){
		arr[i] = p1;
		i++;
		arr[i] = p2;
		i++;
		p1--;
		p2--;
		c--;
	}
	if(n%2 != 0)
	arr[i++] = (n/2+1);	
	
	long long s = 0;
	
	for(int k=1; k<i; k++){
		s = s + abs(arr[k] - arr[k-1]);
		//cout<<arr[k];
	}
		//cout<<k<<endl;
	
	sum[n] = s;
	
	return sum[n];
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<100001; i++){
		sum[i] = 0;
		arr[i] = 0;
	}
	while(T){
		int n;
		cin>>n;
		cout<<pre(n)<<endl;
		T--;
	}
}