/*
matching parenthesis
*/
#include <iostream>
#include <stack>
using namespace std;

stack<char> tmp_stk;

char get_pair(char c){
	if(c=='{')
		return '}';
	else if(c == '[')
		return ']';
	else if(c=='(')
		return ')';
	else if(c == '}')
		return '{';
	else if(c==')')
		return '(';
	else if(c == ']')
		return '[';
		
}

int check(char str1[10000]){
	
for(int i=0; str1[i] != '\0'; i++){
		if(str1[i] == '{'||str1[i] == '['||str1[i] == '(')
			tmp_stk.push(str1[i]);
		else if(tmp_stk.size()==0 || get_pair(str1[i]) != tmp_stk.top())
			return false;
		else
			tmp_stk.pop();	
	}	
	return true;
}

int main(){
	char str1[10000];
	cin>>str1;
	bool result = check(str1);
	cout<<result<<endl;
}