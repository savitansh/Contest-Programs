#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char str1[100001];
int n_steps=0;
int curs = 0;
int make_change(int p1, int p2){
	int pos1 = str1[p1]-'a'+1;
	int pos2 = str1[p2]-'a'+1;
	int v1 = abs(pos1-pos2);
	int v2 = abs(26-pos1-pos2);
	n_steps += min(v1,v2);
	str1[p1] = str1[p2];
}

int _distance(int p1, int p2){
	return abs(p1-p2);
}

int main(){
	int n,curs;
	cin>>n;
	cin>>curs;
	curs--;
	cin>>str1;
	int len = strlen(str1);
	int mid = len/2;

	int p1,p2;
	p1 = mid-1;
	if(len % 2 == 0)
		p2 = mid;
	else
		p2 = mid+1;

	while(p1>=0 && p2<len){
		while(str1[p1]==str1[p2]){
			p1--;
			p2++;
		}
		if(p1<0 || p2>=len)
			break;
		if(_distance(curs,p1) < _distance(curs,p2)){
			if(p1 >= curs){
				while(curs<p1){
					//cout<<"R";
					n_steps++;
					curs++;
				}
				if(curs == p1){
					make_change(curs,p2);
				}
			}else if(p1 < curs){
				while(curs>p1){
					//cout<<"L";
					n_steps++;
					curs--;
				}
				if(curs == p1){
					make_change(curs,p2);
				}
			}
		}else{
			if(p2 >= curs){
				while(curs<p2){
					n_steps++;
					//cout<<"R";
					curs++;
				}
				if(curs == p2){
					make_change(curs,p1);
				}
			}else if(p2 < curs){
				while(curs>p2){
					n_steps++;
					//cout<<"L";
					curs--;
				}
				if(curs == p2){
					make_change(curs,p1);
				}
			}
		}
	}

	cout<<n_steps<<endl;
}