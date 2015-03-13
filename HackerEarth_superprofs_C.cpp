/*
@author savitansh
*/
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


string inp;//[1000000];
char keys[60],original[60];
int main(){
	int n,idx2,idx1;
	cin>>n;
	char c = 'a';
	for (int i = 1; i <= 26; ++i)
	{
		int j = i-1;
		c = 'a' + (char)j;
		keys[i] = c;
		original[i] = c;
	}
	keys[27] = ' ';
	original[27] = ' ';
	for (int i = 28; i <= 54; ++i)
	{
		c = 'A' + (char)(i-28);
		keys[i] = c;
		original[i] = c;
	}
	
	char k1,k2;
	for (int i = 0; i < n; ++i)
	{
		cin>>k1>>k2;
		for (int j = 1; j <= 54; ++j)
		{
			if(keys[j] == k1){
				idx1 = j;
				break;
			}
		}
		for (int j = 1; j <= 54; ++j)
		{
			if(keys[j] == k2){
				idx2 = j;
				break;
			}
		}
		char t = keys[idx1];
		keys[idx1] = keys[idx2];
		keys[idx2] = t;
	}

	//getline(cin,inp);
	while(cin>>inp){
		int i =0;
	for (i = 0; inp[i] != '\0'; ++i)
	{
		char t = inp[i];
		int idx = 0;
		for (int j = 1; j <= 54; ++j)
		{
			if(t == original[j]){
				idx = j;
				break;
			}
		}
		inp[i] = keys[idx];
	}
	if(inp[i+1] != '\n')
	cout<<inp<<" ";
	else
		cout<<inp;
	}
	cout<<endl;
	return 0;
}