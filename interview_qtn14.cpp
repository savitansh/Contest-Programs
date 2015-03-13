/*
find all occurences of anagrams of a word in a string
*/
#include <iostream>
#include <string.h>
using namespace std;

int count[100],count1[100];

int main(){
	char str1[10000];
	cin>>str1;
	char pat[100];
	cin>>pat;
	int len = strlen(pat);
	for(int i=0; i<len;i++){
		count1[pat[i]]++;
	}

	for(int i=0; i<len; i++){
		count[str1[i]]++;
	}

		bool flag = true;
		for(int k=0; k<26; k++){
			if(count1['a'+k] != count['a'+k]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout<<0<<" ";
		}
	int j=0;	
	for(int i=1; str1[i+len-1] !='\0'; i++){
		j = i+len-1;
		count[str1[j]]++;
		count[str1[i-1]]--;

		bool flag = true;
		for(int k=0; k<26; k++){
			if(count1['a'+k] != count['a'+k]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}