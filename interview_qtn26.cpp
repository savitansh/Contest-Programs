#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int x1=0,y1=0;
	int x2=x1,y2=y1;
	string str1;
	cin>>str1;
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i]=='N')
			y2++;
		else if(str1[i]=='S')
			y2--;
		else if(str1[i]=='E')
			x2++;
		else if(str1[i]=='W')
			x2--;
	}
	int path[1000];
	int t=0;
	if(x2 > x1){
		int diff=x2-x1;
		for(int i=0; i<diff; i++)
			path[t++] = 1;
	}
	if(y2 > y1){
		int diff=y2-y1;
		for(int i=0; i<diff; i++)
			path[t++] = 2;
	}
	if(x2 < x1){
	int diff=x1-x2;
		for(int i=0; i<diff; i++)
			path[t++] = 4;	
	}
	if(y2 < y1){
		int diff=y1-y2;
		for(int i=0; i<diff; i++)
			path[t++] = 3;
	}
	sort(path,path+t);
	for(int i=0; i<t; i++){
		if(path[i]==1)
			cout<<'E';
		else if(path[i]==2)
			cout<<'N';
		else if(path[i]==3)
			cout<<'S';
		else
			cout<<'W';
	}
}