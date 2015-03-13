#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::map<long long int, int> m;
long long int strange_nos[1000];
int counter = 0;


int len(int v){
	int l = 0;
	while(v >0)
	{
		v = v /10;
		l++;
	}
	return l;
}

int calc(){
	long long int l,r;
	int l1=counter,l2=counter;
	cin>>l>>r;
	for (int i = 1; i <= counter; ++i)
	{
		if(strange_nos[i] > r)
		{
			l1 = i-1;
			break;
		}	
	}

	for (int i = 1; i <= counter; ++i)
	{
		if(strange_nos[i] > l-1)
		{
			l2 = i-1;
			break;
		}	
	}
	cout<<(l1-l2)<<endl;
	return 0;
}
int main(){
	
	long long int key,t;
	int val,K,l;
	for (int i = 0; i <= 9; ++i)
	{
		m[i] = 1;
	}

std::map<long long int, int>::iterator it;
	for(int l=2; l<=18; l++){
	for(it =m.begin(); it!= m.end(); it++){
		key = it->first; 
		val = it->second;
		if(val < l && val > 0){
			K = l;
			t = key * K;
			while(len(t) <= l){
				if(m[t] == l)
					break;
				if(len(t) == l)
				m[t] = l;
				else
					break;
				t = t * l; 
			}
		}

	}	
	}
		
	for(it =m.begin(); it!= m.end(); it++){
		if(it->second > 0)
		{
			strange_nos[++counter] = it->first;
		}
	}

	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;	
}