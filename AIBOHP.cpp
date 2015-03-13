#include <iostream>
using namespace std;

string s;
int ins[2000][6100];
int inserts(int i, int n){
	int len=0;
	for( len=1; len<n; len++){
		for(int i=n-len-1; i>=0; i--){
		int v1 = min(ins[i+1][(i+len)%2],ins[i][(i+(len-1))%2]);
		if(s[i] != s[i+len]){
			ins[i][(i+len) % 2] = v1+1;

			}
		else
			ins[i][(i+len)%2] = ins[i+1][(i+(len-1))%2];
		cout<<ins[i][(i+len)%2]<<",";
		}

cout<<endl;
	}

	return ins[0][len%3];

}

int calc(){
	cin>>s;
	int n = s.length();
	cout<<inserts(0,n)<<endl;

}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}