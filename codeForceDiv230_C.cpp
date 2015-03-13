#include <iostream>
using namespace std;

long long int find_power(long long int x, int n){
	if(n==0)
		return 1;

	if(n==1)
		return x;

	if(n%2 != 0)
		return x*find_power(x*x,n/2);
	return find_power(x*x,n/2);
}
int main(){
	long long int n;
	cin>>n;
	
	cout<<(4*find_power(2,n-1))<<endl;
}