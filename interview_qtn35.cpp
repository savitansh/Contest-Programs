/*
 remove duplicate characters from string
*/
#include <iostream>
using namespace std;

int swap(string s, int p1, int p2){
	char t = s[p1];
	s[p1] = s[p2];
	s[p2] = t;
}

int count[300];

int main(){
	string str1;
	cin>>str1;
	int n = str1.length();

	for(int i=0; i<n; i++){
		if(count[str1[i]] == 1)
			str1[i]= 0;
		else
			count[str1[i]] = 1;
	}
	cout<<str1<<endl;
	int p1 = n, p2 = n;
	for(int i=0; i<n; i++)
		if(str1[i] == 0)
		{
			p1 = p2 = i;
			break;
		}

	while(p2 < n){
		if(str1[p2] != str1[p2+1])
		{
			swap(str1,p1,p2+1);
			p1++;
			p2++;
		}
		else
			p2++;
	}	
	str1[p1] = '\0';
	cout<<str1<<endl;
}