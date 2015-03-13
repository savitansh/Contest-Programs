#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
vector<string>::iterator it,last;
int main(){
	string s;
	char q[100];
	cin>>q;
	
	q[3] = '\0';
	string s2 = string(q);
	cout<<s2<<endl;
	for(int i=0; i<5; i++)
	{
		cin>>s;
		v.push_back(s);
	}	
	sort(v.begin(),v.end());
	last = unique(v.begin(),v.end());
	for(it = v.begin(); it!=last; it++){
		cout<<*it<<endl;
	}
}