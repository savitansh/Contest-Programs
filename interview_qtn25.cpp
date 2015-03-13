/*
- Given two sets of elements we have to find whether the
 resulting set of LCM of the two sets would be equal or not.
Ex:- Let the set be X = {2,3,4}
Then the LCM set would be consisting of all the LCM of any 
subset of the given set.
In this case, LCM(X)={2,3,4,6,12}
Constraints:
 Number of elements in both sets donot exceed 50.
 Range of elements i.e A_i and B_i<=10^9
 */
#include <iostream>
using namespace std;

int generate_primes(){

}
int check(){
	for(p in primes){
		for(int i=0; i<n; i++){
			int val = A[i];
			int t = 0;
			while(val%p==0){
				t++;
				val = val / p;
			}
			fact1[i] = t;
		}
		for(int i=0; i<m; i++){
			int val = B[i];
			int t = 0;
			while(val%p==0){
				t++;
				val = val / p;
			}
			fact2[i] = t;
		}
		

	}
}

int main(){
	
}