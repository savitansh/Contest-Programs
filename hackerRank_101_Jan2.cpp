#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int calc(){

	set<long long int> st;
	set<long long int>::iterator it;

	int n=0;
	long long int m,val=-1;
	cin>>n>>m;
		long long int a=0,p=0;

	for(int i=0; i<n; i++)
	{
		cin>>a;
		p =( p + a)%m;
		
		it = st.upper_bound(p);
		if(it != st.end()){
			val = max(val,m-(*it - p));
		}else{
			val = max(val,p);
		}
		st.insert(p);
	}
	cout<<val<<endl;
	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
}