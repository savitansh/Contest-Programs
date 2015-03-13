#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000000
using namespace std;

int prime[100000];

vector<int> primes;
vector<int>::iterator it;

int generate_primes(){
	prime[1] = 1;
	for(int i=2; i<1000; i++){
		for(int j=2; j*i<100000; j++)
			prime[i*j] = 1;
	}

	for(int i=0; i<100000; i++){
		if(prime[i] == 0){
			primes.push_back(i);
		}
	}
}

int process(){
	int siz = primes.size();

	for(int i=0; i<siz; i++){
		int j = primes[i];
		int c = 0;
		while(j > 0){
			if(M.contains(j)){
				M[j] = c;
				c++;
				j = j - K;
			}
		}
	}
}


	int arr[1000][1000],D[1000][1000];

int main(){
	generate_primes();
	process();
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	}

	int min_val = 100000,s=0,loc_c,loc_r;

	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			
			s = M[arr[i-1][j-1]] + M[arr[i-1][j+1]] + M[arr[i+1][j-1]] + M[arr[i+1][j+1]] + M[arr[i][j]];
			if(s < min_val){
				min_val = s;
				loc_r = i;
				loc_c = j;
 			}
		}
	}
	if(min_val < 100000){
	cout<<"yes"<<endl;
	cout<<min_val<<endl<<loc_r+1<<" "<<loc_c+1<<endl;
	}else
	cout<<"no"<<endl;
return 0;
}