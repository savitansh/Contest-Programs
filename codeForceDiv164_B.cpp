#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int val = 0;
	int n_attempts = n;
	for (int i = 1; i < n; ++i){
		val = val + i * n_attempts;
		n_attempts--;
		val = val - i;
	}
	val = val + n;
	cout<<val<<endl;
}