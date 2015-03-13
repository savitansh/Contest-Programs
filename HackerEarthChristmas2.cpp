/*
@author savitansh
*/
#include <iostream>
using namespace std;

int main(){
	string inp;
	cin>>inp;
	for(int i=0; inp[i] != '\0'; i++){
		st[inp[i]].push_back(i);
	}

	int q;
	cin>>q;
	while(q){
		int k;
		char c;
		cin>>k>>c;
		k--;
		int pos = st[c][k];
		inp[pos] = -1;

	}
}