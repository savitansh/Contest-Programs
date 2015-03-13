/*
@author savitansh
*/
#include <iostream>
#include <set>
using namespace std;

set<int> vassels;

int find_next(int v){
	set<int>::iterator itup;
	itup = vassels.find(v);
	if(itup == vassels.end())
		itup = vassels.upper_bound(v);
	if(itup != vassels.end()){
	int val = *itup;
	return val;	
	}else
	return -1;
}

long long int size[300000];
long long int capacity[300000];

int main(){
	int v,v2,n,choice,m;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>size[i];
		capacity[i] = size[i];
	}
		

	cin>>m;
	for(int i=1; i<=n; i++){
		if(capacity[i] > 0)
			vassels.insert(i);
	}

	for(int i=0; i<m; i++){
		cin>>choice;
		if(choice == 1){
			int x;
			cin>>v>>x;
			if(capacity[v] > x)
			{
				capacity[v] = capacity[v] - x;
			}else if(capacity[v] == x){
				capacity[v] -= x;
				vassels.erase(v);
			}else if(capacity[v] < x){
				while(1){
					if(x > 0)
						v2 = find_next(v);
					else
					break;
				if(v2 == -1)
					break;

				if(capacity[v2] > x){
					capacity[v2] = capacity[v2] - x;
					break;
					}	else if(capacity[v2] == x){
						capacity[v2] =0;
						vassels.erase(v2);
						break;
					}else if(capacity[v2] < x){
						x = x - capacity[v2];
						capacity[v2] = 0;
						vassels.erase(v2);
						v = v2;
					}
				}

			}
		}	else if(choice == 2){
			cin>>v;
			cout<<(size[v] - capacity[v])<<endl;
		}
	}
}