/*
@author savitansh
1.Find number of elements less than v which are divisible by atleast one of given primes
2. Use binary search to find nth on bulb
*/
#include <iostream>
#define EXP 15
using namespace std;

int primes[] = {2,3,5,7};

int findNumOfMultiples(int v , int fact){
	int n = v / fact;
	return n;
}

int findNumOfOnBulbs(int v){
	int max1 = EXP;

	int onBits[40];
	for (int i = 0; i < 40; ++i)
	{
		onBits[i] = 0;
	}

	int res = 0;
	for(int j=1; j<=max1; j++){
		
		int t = j;
		int pos = 0;
		int numOfOnBits = 0;

		int fact = 1;
			
		while(t>0){
			if(t & 1 == 1){
				fact = fact * primes[pos];
				numOfOnBits++;
			}
			t = t>>1;
			pos++;
		}
		//cout<<fact<<":"<<numOfOnBits<<endl;
		if(numOfOnBits % 2 == 0)
			res = res - v/fact;
		else
			res = res + v/fact;
	}
return res;
}

int getNthOnBulb(int low , int high , int k){
	int mid = (low + high) /2;
	int res = findNumOfOnBulbs(mid);
	if(res > k){
		getNthOnBulb(low , mid , k);
	}else if(res < k){
		getNthOnBulb(mid+1,high , k);
	}	else
	return mid;
}

int main(){

	//cout<<findNumOfOnBulbs(20)<<endl;
	cout<<getNthOnBulb(1,1000000,10)<<endl;
}