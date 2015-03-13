#include <iostream>
#include <algorithm>
using namespace std;

char str1[4][4];
	int arr[16];
	
int main(){
	int k;
	cin>>k;
	int t = 0;
	for(int i=0; i<4; i++){
		cin>>str1[i];
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(str1[i][j] != '.'){
				arr[t] = str1[i][j]-'0';	
				t++;
			}
		}
	}
	sort(arr,arr+t);
	bool flag = true;

		
	for(int i=0; i<t-1; i++){
		int counter = 0;
		int same = 0;
		while(arr[i] == arr[i+1]){
			counter++;
			i++;
			same = 1;
		}
		if(same == 1)
			i--;
		if((counter+1) > k*2){
			flag = false;
			break;
		}
	}
	if(flag == true){
		cout<<"YES"<<endl;
	}else
	cout<<"NO"<<endl;

	return 0;
}