#include <iostream>
using namespace std;

int main(){
	long long int n;
	int T;
	cin>>T;
	while(T){
	cin>>n;
	n--;
	long long int s = 0, k=0;
	while(n>=0){
		s += (n*(n+1)) / 2;
		s += (k*(k+1)) / 2;
		n--;
		k++;
	}
	cout<<s<<endl;
	T--;
	}
}