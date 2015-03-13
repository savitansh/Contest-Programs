#include <iostream>
#include <string.h>
using namespace std;

int arr[1000];
int main(){
	char str1[1000];
	arr[0] = 0;
	arr[1] = 1;
	cin>>str1;
	if(str1[1] != '\0'){
		int val = (str1[0]-'0')*10 + (str1[1]-'0');
		if(val <= 26){
			arr[2] = 2;
		} else
			arr[2] =1;
	}
	//cout<<arr[1]<<endl;
	int len = strlen(str1);

	for(int i=2; str1[i] != '\0'; i++){
		int val = (str1[i-1]-'0')*10 + (str1[i]-'0');
		if(val<=26)
			arr[i+1] = arr[i-1] + arr[i];
		else
			arr[i+1] = arr[i];
	}
	cout<<arr[len]<<endl;
}