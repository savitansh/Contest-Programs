#include<iostream>
using namespace std;


long long int powers[80];
int generatePowers(){
	powers[0] = 1;
	for(int i=1; i<100; i++){
		powers[i] = powers[i-1] * 2;
	}
	return 0;
}

int calc(long long int N){
	
	bool turn = false;
	while(N > 1){
		long long int tmp = N;
		int ones = 0;
		int bitCount = 0;
		while(tmp > 0){
			tmp = tmp>>1;
			bitCount++;
			if(tmp & 1 != 0)
				ones++;
		}
		if(ones > 1)	
			N = N - powers[bitCount-1];
		else
			N = N >> 1;
		//cout<<N<<" ";
		turn = !turn;
	}

	if(turn == true)
		cout<<"Louise"<<endl;
	else
		cout<<"Richard"<<endl;

	return 0;
}

long long int N = 0;

int main(){
	int T=0;
	cin>>T;
	generatePowers();

	while(T){
		cin>>N;
		cout<<N<<endl;
		calc(N);
		T--;
	}
	return 0;
}