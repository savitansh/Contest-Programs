/* 
@author savitansh
min priority queue 
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

long long int candidates[100000];
int count1[100000];


int calc(){
map<long long int, priority_queue<int,std::vector<int>,greater<int> > > elementGroups;
priority_queue<int,std::vector<int>,greater<int> > groups;

	int n=0;
	cin>>n;

	for (int i = 0; i < n; ++i){
	
			cin>>candidates[i];
	}	

sort(candidates,candidates+n);

for(int i=0; i<n; i++){
	
	long long int candidate = candidates[i];
	int smallestGroupSize = 0;
	if(elementGroups.find(candidate-1) != elementGroups.end() ){

		groups = elementGroups[candidate-1];
		smallestGroupSize = groups.top();
		smallestGroupSize++;
		elementGroups[candidate-1].pop();
	}
	elementGroups[candidate].push(smallestGroupSize);
	
	
}

int minTeamSize = 1000000,size =0;
	
for (int i=0; i<n; i++){
	long long int candidate =candidates[i];
	if(elementGroups.find(candidate+1) == elementGroups.end()){
		groups = elementGroups[candidate];
		int size = groups.top();
		if(size< minTeamSize){
	
		minTeamSize = size;
	}
	}
	
}

cout<<minTeamSize<<endl;
return 0;
}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}