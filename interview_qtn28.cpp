/*
rank of word in dictionary
all characters unique
*/
#include <iostream>
using namespace std;

string word;

int F[10000];
int mark[100];

int fact(){
	F[0] = 1;
for(int i=1; i<1000;i++)
	F[i] = F[i-1] * i;
}

int main(){
	fact();
	cin>>word;
	int n=0,rank=0;
	for(int i=0; word[i] != '\0'; i++){
		mark[word[i]-'a'] = 1;
	}
	
	int n1=0;

	for(int i=0; word[i] != '\0'; i++){
		
		n1 = 0;
		n = 0;
		for(int k=0;k<=26; k++)
		{
			if(mark[k]==1 && (word[i]-'a')>k)
			n1++;
			if(mark[k] == 1)
				n++;
		}
		n--;
		
		rank = rank + n1*F[n];
		mark[word[i]-'a'] = 0;
		
	}		
	cout<<rank+1<<endl;
}