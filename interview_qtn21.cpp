/*
number of distinct pallindromic substrings
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
vector<string>::iterator it,last;

int add_to_list(string str1, int k, int j){
	int t=0;
	char q[1000];
	for(int i=k; i<=j; i++){
		q[t++] = str1[i];
	}
	q[t] = '\0';
	string s = string(q);
	v.push_back(s);
}

int count_unique(){
	int counter = 0;
	sort(v.begin(),v.end());
	last = unique(v.begin(),v.end());
	for(it = v.begin(); it!=last; it++)
		counter++;
	return counter;
}

int main(){
	char str1[1000];
	cin>>str1;
	int n = strlen(str1);
	int k=0,j=0;
	int count = 0;
	for(int i=0; i<n; i++){
		k = i;
		j = i;
		while(k>=0 && j<n){
			if(str1[k]==str1[j]){
				count++;	
				add_to_list(str1,k,j);
			k--;
			j++;
			}else
			break;
		}
		k = i;
		j = i+1;
		while(k>=0 && j<n){
			if(str1[k]==str1[j]){
				add_to_list(str1,k,j);
				count++;	
			k--;
			j++;
			}else
			break;	
		}
	}
	count = count_unique();
	cout<<count<<endl;
}