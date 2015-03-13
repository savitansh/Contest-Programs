#include <iostream>
using namespace std;

string inp;
int digits[16];
int facts[10];

int main(){
	int n;
	cin>>n;
	cin>>inp;
	for(int i=0; i<n; i++){
		digits[i] = inp[i] - '0';
	}
	for(int i=0; i<n; i++){
		if(digits[i]==2){
			facts[2]++;
		}else if(digits[i]==3){
			facts[2]++;
			facts[3]++;
		}else if(digits[i]==4){
			facts[2] += 3;
			facts[3]++;
		}else if(digits[i]==5){
			facts[2] += 3;
			facts[3]++;
			facts[5]++;
		}else if(digits[i]==6){
			facts[2] += 4;
			facts[3] += 2;
			facts[5]++;
		}else if(digits[i]==7){
			facts[2] += 4;
			facts[3] += 2;
			facts[5]++;
			facts[7]++;
		}else if(digits[i]==8){
			facts[2] += 7;
			facts[3] += 2;
			facts[5]++;
			facts[7]++;
		}else if(digits[i] == 9){
			facts[2] += 7;
			facts[3] += 4;
			facts[5]++;
			facts[7]++;
		}
	}
	int count = 0;
	while(facts[7]>0){
		cout<<7;
		facts[7]--;
		facts[5]--;
		facts[3] -= 2;
		facts[2] -= 4;
		count++;
	}
	while(facts[5]>0){
		cout<<5;
		facts[5]--;
		facts[3] -= 1;
		facts[2] -= 3;
		count++;
	}
	while(facts[3]>0){
		cout<<3;
		facts[3]--;
		facts[2]--;
		count++;
	}
	while(facts[2]>0){
		cout<<2;
		facts[2]--;
		count++;
	}
	
	cout<<endl;
}