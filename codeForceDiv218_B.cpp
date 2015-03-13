#include <iostream>
using namespace std;

int main(){
	long long int a,b;
	cin>>a>>b;
	int powers[2][3];

	long long int tmp = a;
	int pow1 = 0;
	while(tmp%2==0){
		tmp = tmp/2;
		pow1++;
	}
	powers[0][0] = pow1;
	pow1 = 0;
	tmp = a;
	while(tmp%3 == 0){
		tmp = tmp/3;
		pow1++;
	}
	powers[0][1] = pow1;

	pow1 = 0;
	tmp = a;
	while(tmp%5 == 0){
		tmp = tmp/5;
		pow1++;
	}
	powers[0][2] = pow1;

	pow1 = 0;
	tmp = b;
	while(tmp%2 == 0){
		tmp = tmp/2;
		pow1++;
	}
	powers[1][0] = pow1;

	pow1 = 0;
	tmp = b;
	while(tmp%3 == 0){
		tmp = tmp/3;
		pow1++;
	}
	powers[1][1] = pow1;

	pow1 = 0;
	tmp = b;
	while(tmp%5 == 0){
		tmp = tmp/5;
		pow1++;
	}
	powers[1][2] = pow1;

	for(int i=0; i<3; i++){
		int min1 = min(powers[0][i],powers[1][i]);
		powers[0][i] = powers[0][i] - min1;
		powers[1][i] = powers[1][i] - min1;
	}

	// for(int i=0; i<2; i++){
	// 	for(int j=0;j<3;j++){
	// 		cout<<powers[i][j];
	// 	}
	// 	cout<<endl;
	// }
	long long int factor = 1;
	
	for(int i=0; i<powers[0][0]; i++)
		factor = factor * 2;

	for(int i=0; i<powers[0][1]; i++)
		factor = factor * 3;

	for(int i=0; i<powers[0][2]; i++)
		factor = factor * 5;
	a = a/factor;

	factor = 1;
	
	for(int i=0; i<powers[1][0]; i++)
		factor = factor * 2;

	for(int i=0; i<powers[1][1]; i++)
		factor = factor * 3;

	for(int i=0; i<powers[1][2]; i++)
		factor = factor * 5;
	b = b/factor;

	
	if(a != b)
		cout<<-1<<endl;
	else{
		int total = 0;
		for(int i=0; i<2; i++){
			for(int j=0;j<3;j++){
			total += powers[i][j];
			}
		 }

		cout<<total<<endl; 
	}
	return 0;
}