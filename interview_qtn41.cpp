/*
regex match for * and .
*/
#include <iostream>
using namespace std;

bool match_pattern(string input, string pat){

	int p1 = 0,p2=0;
	int len1 = input.length();
	int len2 = pat.length();

	while(p1<len1 && p2<len2){
		if(pat[p2+1]=='*'){
			while(input[p1] == pat[p2])
				p1++;
			p2 = p2 + 2;
			if(p2 >= len2-1)
				break;
		}
		else {
		if(pat[p2] != '.'){
			if(input[p1] != pat[p2])
				return false;	
		}
		p1++;
		p2++;
		}
	}
	return true;

}

int main(){
	string input,pat;
	cin>>input;
	cin>>pat;

	cout<<match_pattern(input,pat)<<endl;
}