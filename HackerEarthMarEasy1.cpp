#include <iostream>
#include <stdlib.h>
using namespace std;

int pos[250];
int digit[250];

int get_dist(char c1, char c2){
	int p1 = digit[c1];
	int p2 = digit[c2];
	return abs(p1-p2);
}

int get_presses(char c){
	return pos[c];
}

int main(){
	pos['0'] = 2;
	pos['.'] = pos['a'] = pos['d'] = pos['g'] = pos['j'] =  pos['m'] =  pos['p'] =  pos['t'] =  pos['w'] =  pos['_'] = 1;
	pos[','] = pos['b'] = pos['e'] = pos['h'] = pos['k'] =  pos['n'] =  pos['q'] =  pos['u'] =  pos['x']  = 2;
	pos['?'] = pos['c'] = pos['f'] = pos['i'] = pos['l'] =  pos['o'] =  pos['r'] =  pos['v'] =  pos['y']  = 3;
	pos['s'] = pos['z'] = 4;
	pos['!'] =  pos['2'] = pos['3'] = pos['4'] = pos['5'] = pos['6'] = pos['8'] = 4;
	pos['7'] = pos['1'] = pos['9'] = 5;

	digit['.'] = digit[','] = digit['?'] = digit['!'] = digit['1'] = 1;
	digit['a'] = digit['b'] = digit['c'] = digit['2'] =2;
	digit['d'] = digit['e'] = digit['f'] = digit['3'] =3;
	digit['g'] = digit['h'] = digit['i'] = digit['4'] =4;
	digit['j'] = digit['k'] = digit['l'] = digit['5'] =5;
	digit['m'] = digit['n'] = digit['o'] = digit['6'] =6;
	digit['p'] = digit['q'] = digit['r'] = digit['s'] = digit['7'] =7;
	digit['t'] = digit['u'] = digit['v'] = digit['8'] =8;
	digit['w'] = digit['x'] = digit['y'] = digit['z'] = digit['9'] =9;
	digit['_'] = digit['0'] = 0;

	int T;
	cin>>T;
	
	while(T){
	
	string s;
	cin>>s;
	int t = 0,tim=0;
	if(digit['.'] != digit[s[0]])
	tim += 1;
	tim += pos[s[0]];
	//cout<<tim<<endl;
	for(int i=1; s[i] != '\0'; i++){
		
		if(digit[s[i]] != digit[s[i-1]])
		tim += 1;

		tim += pos[s[i]];
	//	cout<<s[i]<<","<<tim<<endl;
	}
	cout<<tim<<endl;
	T--;
	}
return 0;
}