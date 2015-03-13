#include <iostream>
using namespace std;

int count[30][100000];

int main(){
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;

	int len = s.length();

	for(int i=0; i<len; i++){
		for(char c = 'a'; c<='z'; c++){
		if(c == s[i])
		count[c- 'a'][i+1] = count[c - 'a'][i] + 1;
		else
		count[c- 'a'][i+1] = count[c - 'a'][i];
		}
	}

	
	for(int i=0; i<q; i++){
		int l,r,k;
		cin>>l>>r>>k;
		l--;
		r--;
		bool flag = false;

		char j = 'a';
		while(j<='z'){
			int c = count[j - 'a'][r+1] - count[j - 'a'][l];
			//cout<<j<<","<<c<<endl;
			if(c>=k){
				cout<<j<<endl;
				flag = true;
				break;
			}else{
				k = k - c;
			}
			j++;
		}
		if(flag == false)
			cout<<"Out of range"<<endl;
	}
}