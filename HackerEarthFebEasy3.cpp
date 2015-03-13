#include <iostream>
#include <vector>
#include <algorithm>
#define MAX1 1000000
using namespace std;

vector<int> worst;
int M[1001][21];

int update_worst_list(int prio){
	int min1  = MAX1;

	int sz = worst.size();

	for(int i=0; i<sz; i++){
		if(worst[i] !=MAX1 && M[worst[i]][prio] < min1){
			min1 = M[worst[i]][prio];
		}
	}
		for(int i=0; i<sz; i++){
		if(worst[i] !=MAX1 &&  M[worst[i]][prio] > min1){
			worst[i] = MAX1;
		}
	}
}

int main(){
	int st,sub,ns,prio,min1;
	cin>>st>>sub;
	
	for(int i=1; i<=st; i++){
		for(int j=1; j<=sub; j++){
			cin>>M[i][j];
		}
	}
	int q;
	cin>>q;
	
	for(int i=0; i<q; i++){
		worst.clear();
		cin>>ns;
		if(ns == 0)
			continue;

		cin>>prio;
		min1 = MAX1;
			for(int i=1; i<=st; i++){
				if(M[i][prio] < min1){
					min1 = M[i][prio];
				}
			}
			for(int i=1; i<=st; i++){
				if(M[i][prio] == min1)
					worst.push_back(i);
			}
		
		for(int k=0; k<ns-1; k++){
		cin>>prio;
		update_worst_list(prio);
		
		}
		sort(worst.begin(),worst.end());
	cout<<worst[0]<<endl;
	
	}
	return 0;
}
