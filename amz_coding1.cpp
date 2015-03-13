#include <iostream>
using namespace std;
/*
@author savitansh
problem : You have to find a string in two-dimensional array. 
The input contains 2-D array of characters and given string. 
You can move in one of eight directions . 
The output contains location of first letter of string if string found completely,
 otherwise return -1. Any one out of multiple answers is accepted,if possible.
For example, Input:
b	t	g
p	a	d
r	k	j

String: rat
Output: (2,0)
*/

char mat[100][100];
char str1[100];

int track(int i, int j, int idx){
	if(idx == n)
		return 1;
	if(i < 0 || i>=m || j < 0 || j>=m)
		return 0;
	int r = 0;
	if(str1[idx] == mat[i][j]){
				r = max(r,track(i,j+1,idx+1));
				r = max(r,track(i,j-1,idx+1));
				r = max(r,track(i+1,j,idx+1));
				r = max(r,track(i-1,j,idx+1));
				r = max(r,track(i+1,j+1,idx+1));
				r = max(r,track(i-1,j-1,idx+1));
				r = max(r,track(i-1,j+1,idx+1));
				r = max(r,track(i+1,j-1,idx+1));
				return r;
	}else
	return 0;
}

int find(){
	int r = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			r = 0;
			if(mat[i][j] == str1[idx]){
				r = max(r,track(i,j+1,idx+1));
				r = max(r,track(i,j-1,idx+1));
				r = max(r,track(i+1,j,idx+1));
				r = max(r,track(i-1,j,idx+1));
				r = max(r,track(i+1,j+1,idx+1));
				r = max(r,track(i-1,j-1,idx+1));
				r = max(r,track(i-1,j+1,idx+1));
				r = max(r,track(i+1,j-1,idx+1));
				if(r == 1){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}		
		}
	}
}

int main(){
	int m = 3;
for(int i=0; i<m; i++){
	for(int j=0; j<m; j++){
		cin>>mat[i][j];
	}
}

cin>>str1;
find();
}