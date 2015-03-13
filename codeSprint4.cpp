#include <iostream>
#include <string.h>
using namespace std;

int bitmap[30];
int calc(){

	char keys[100],inp[100];
	cin>>keys;
	cin>>inp;

	int len = strlen(keys);
	for (int i = 0; i < len; ++i)
	{
		bitmap[(keys[i]-'a')] = 1;
	}

	int len2 = strlen(inp);
	int tofix = 0;
	for (int i = 0; i < len2; ++i)
	{
		if(bitmap[(inp[i]-'a')] == 1){
			tofix++;
			bitmap[(inp[i]-'a')] = 0;
		}
	}

	cout<<tofix<<endl;

	for (int i = 0; i < 30; ++i)
	{
		bitmap[i] = 0;
	}

	return 0;
}
int main(){

	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}