#include <iostream>
using namespace std;

int main(){
	char str1[100000];
	cin>>str1;
	int maxlen = 0, currlen = 0;

	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i] == 'a'){
			currlen += 1;
			if(currlen > maxlen){
				maxlen = currlen;
			}
		}else
		currlen = 0;
	}
	for(int i=0; i<maxlen+1; i++){
		cout<<'a';
	}
	cout<<endl;
	return 0;
}