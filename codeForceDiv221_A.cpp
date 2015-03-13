#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	char str1[1000000];
	scanf("%s",str1);

	int lever = 0;
	for (int i = 0; str1[i] != '\0'; ++i)
	{
		if(str1[i] == '^'){
			lever = i+1;
			break;
		}
	}

	long long int sum = 0;
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i]-'0' >=0 && str1[i]-'0' <=9){
			int val = str1[i]-'0';
			int pos = lever - (i+1);
			sum += val*pos;
		}
	}
	if(sum == 0){
		cout<<"balance"<<endl;
	}else if(sum > 0){
		cout<<"left"<<endl;
	}else
		cout<<"right"<<endl;

	return 0;		
}