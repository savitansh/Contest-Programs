#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//long long int vec[1000000];
vector<long long> vec;
vector<long long int>::iterator it;
int main(){
	int n;
	int k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		long long int a;
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());

	long long int count =0;
	for(int x=0; x<n; x++){
		for(int y=x+1; y<n; y++){
				long long q = k/(vec[x]*vec[y]);
				
					it = upper_bound(vec.begin(),vec.end(),q);
					
					int l = 0;
					if(it-(vec.begin()) > y)
					l = it-(vec.begin()+y)-1;
					if(l > 0)
					count += l;
				
			
		}
	}
	cout<<count<<endl;
}