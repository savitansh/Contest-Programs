/*
@author savitansh
find a^b % c^d
*/

#include<iostream>
#include<map>
using namespace std;


int primes[1000001];

int generatePrimes(){
	primes[1] = 1;

	for (int i = 2; i*i <= 1000000; ++i)
	{
		if(primes[i] == 0){
			for (int j = 2; i*j <= 1000000; ++j)
			{
				primes[i*j] = 1;
			}	
		}
		
	}
}

int findPower(long long int factor , long long int val){
	int f = factor;
	int power1= 0;
	while(val %factor == 0){
		factor = factor * f;
		power1++;
	}	
	return power1;
}

map<int,long long int> generateFactors_a(long long int a , long long int b){

std::map<int, long long int> map_a;

	for(int i=2; i<=1000000; i++){
		if(primes[i] == 0 && a%i==0){
			long long int expo = findPower(i , a);
			map_a[i] = expo * b;
		}
	}
	return map_a;
}


map<int,long long int> generateFactors_c(long long int c , long long int d){

std::map<int, long long int> map_c;

	for(int i=2; i<=1000000; i++){
		if(primes[i] == 0 && c%i==0){
			long long int expo = findPower(i , c);
			map_c[i] = expo * d;
		}
	}
	return map_c;
}


int calc(){
	long long int a=0,b=0,c=0,d=0;
	cin>>a>>b>>c>>d;

	map<int,long long int>  ma = generateFactors_a(a,b);
	map<int,long long int>  mc = generateFactors_c(c,d);	

	map<int,long long int>::iterator it;

	bool indiv = false;

	for(it = mc.begin(); it != mc.end(); it++ ){
		int factor = it->first;
		long long int exp = it->second;
		cout<<factor<<":"<<exp<<endl;
		if(ma.find(factor) != ma.end()){
			long long int k = ma[factor];
			if(k<exp){
				indiv = true;
				break;
			}
		}
	}
	if(indiv == true)
		cout<<"Not divisible";
	else
		cout<<"Divisible";
	cout<<endl;
}

int main(){
	generatePrimes();
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}