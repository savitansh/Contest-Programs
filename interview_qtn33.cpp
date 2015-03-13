/*
*/ 
#include <iostream>
using namespace std;

int fun(string str1){

	char curr = str1[0];
	int j = 0;
	while(str1[j] != '\0')
	{
		int counter = 0;
	while(curr == str1[j]){
		counter++;
		j++;
	}
	cout<<curr<<counter;
	curr = str1[j];
	}
	cout<<endl;
}

int main(){
	fun("AAABBCDEFFFG");
}