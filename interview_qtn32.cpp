/*
print all spaced strings from a string
*/
#include <iostream>
#include <string>
using namespace std;
	
int print_string(string str1){
	int n = str1.length();

	for(int k=0; k<4; k++)
	{
		int v = 1;
		for(int i=0; i<n; i++){
		if(v&k){
			cout<<str1[i];
		}else
			cout<<str1[i]<<" ";
			
		v = v*2;	
	}
	cout<<endl;
	}
}
int main(){
string str1;
cin>>str1;
print_string(str1);	
}