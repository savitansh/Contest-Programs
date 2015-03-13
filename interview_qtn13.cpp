/*
print last 10 lines of given string
if there are less than 10 then print complete string
*/
#include <iostream>
using namespace std;

int main(){
	const char str1[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10";
	//cin>>str1;
	//cout<<str1;
	int counter = 0;
	for(int i=0; str1[i]!='\0';i++)
	{
		if(str1[i] -'\n' == 0)
			counter++;
	}
	cout<<counter<<endl;
	if(counter > 10){
		int diff = counter-10+1;
		int i=0;
		for(i=0; str1[i] != '\0'; i++){
			if(str1[i] -'\n' == 0)
				diff--;
			if(diff==0)
				break;
		}
		for(int j=i+1;str1[j]!='\0'; j++)
			cout<<str1[j];
		cout<<endl;
	}
	else
	cout<<str1<<endl;	
}