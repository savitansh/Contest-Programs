#include <iostream>
using namespace std;

int primes[1000000];
int primesList[1000000];
int smallestFact[1000000];

int generatePrimes(){
	for(int i=2; i*i<1000000; i++){
		for(int j=2; i*j<1000000; j++){
			primes[i*j] = 1;
		}
	}

	int j=0;
	for (int i = 0; i < 1000000; ++i)
	{
		if(primes[i] == 0)
			primesList[j++] = i;
	}
	return j;
}
int main(){
	int n = generatePrimes();
	for (int j = 0; j < 50; ++j)
	{
		smallestFact[j] = primesList[j] * primesList[j+1];
		cout<<primesList[j]<<":"<<smallestFact[j]<<endl;		
	}
	return 0;
}