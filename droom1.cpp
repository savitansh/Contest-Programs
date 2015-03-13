#include <iostream>
#include <string>
using namespace std;

int Weight[300];

int calc(){
	int count = 0,K;
	string s;
	cin>>K;
	cin>>s;
	int p1 = 0,p2 = -1;
	int wt = 0;
	int len = s.length();
	while(p2 < len){
		if(wt == K){
			count++;
			p2++;
			wt += Weight[s[p2]];
		}else if(wt > K){
			wt -= Weight[s[p1]];
			p1++;
			
		}else{
			p2++;
			wt += Weight[s[p2]];
		}
	}
	cout<<count<<endl;
}

int main(){
	Weight['a']=1;
Weight['b']=2;
Weight['c']=3;
Weight['d']=4;
Weight['e']=5;
Weight['f']=6;
Weight['g']=7;
Weight['h']=8;
Weight['i']=9;
Weight['j']=10;
Weight['k']=11;
Weight['l']=12;
Weight['m']=13;
Weight['n']=14;
Weight['o']=15;
Weight['p']=16;
Weight['q']=17;
Weight['r']=18;
Weight['s']=19;
Weight['t']=20;
Weight['u']=21;
Weight['v']=22;
Weight['w']=23;
Weight['x']=24;
Weight['y']=25;
Weight['z']=26;

	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}