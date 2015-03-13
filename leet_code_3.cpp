/*
reverse words of string
test cases :
{"  ",""," abcd "," abcd efgh ","a","abcd efgh  "}
*/
#include <iostream>
#include <string>
using namespace std;


string input;

int swap(string &input, int i, int j){
	char c = input[i];
	input[i] = input[j];
	input[j] = c;
}

int reverse(string &input, int i, int j){
	int m = j;
	for(int k=i; k<m; k++){
		swap(input,k,m);
		m--;
	}
}

void reverse_words(string &s){
	int len = s.length();
	char s2[100000];
	int j=0;
	int i=0;
		
	
	while(s[i] == ' ' && i<len)
	i++;

	while(i<len){
		if(s[i] != ' '){
			s2[j++] = s[i];
			i++;
		}else{
			s2[j++] = s[i];
			while(s[i] == ' ')
				i++;
		}
	}	
	if(s2[j-1] == ' ')
		s2[j-1] = '\0';
	else
		s2[j] = '\0';

	s = s2;
	len = s.length();

	reverse(s,0,len-1);
	for(int i=0; i<len-1; i++){
		for(j=i; s[j] != ' ' && s[j] != '\0'; j++);
		if(s[j] == ' '){
			reverse(s,i,j-1);
			i = j;
		}else if(s[j] == '\0'){
			reverse(s,i, j-1);
			break;
		}
	}
}

int main(){
	
//	getline(cin,input);
	string s = "abcd efgh";
	reverse_words(s);

	cout<<s;
}