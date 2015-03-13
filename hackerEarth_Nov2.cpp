#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


string str1;//[1000000];
	int flag[1000000];
//int m[255];
map<char,int> m;
int cumm[1000000];


// int to_lower(){
// 	for (int i = 0; str1[i] != '\0'; ++i)
// 	{
// 		if(str1[i] < 97)
// 		str1[i] = str1[i] + 32;
// 	}
// 	return 0;
// }

int main(){
	getline(cin,str1);
//	scanf("%s",str1);
	//to_lower();
	//cout<<str1<<endl;
		// m['h'] = 2;
		// m['a'] = 2;
		// m['c'] = 1;
		// m['k'] = 1;
		// m['e'] = 2;
		// m['r'] = 2;
		// m['t'] = 1;
		for(int j=0;j<11; j++){
				m[str1[j]]++;
		}

if(m['h']+m['H']==2 && m['a']+m['A']==2 && m['c']+m['C']==1
 && m['k']+m['K']==1 && m['e']+m['E']==2 && m['r']+m['R']==2 && m['t']+m['T']==1){
			flag[0] = 1;
		}
int s =0 , e = 11;
while(str1[e]!='\0'){
		m[str1[s]]--;
		m[str1[e]]++;
		s++,e++;
if(m['h']+m['H']==2 && m['a']+m['A']==2 && m['c']+m['C']==1
 && m['k']+m['K']==1 && m['e']+m['E']==2 && m['r']+m['R']==2 && m['t']+m['T']==1){
			flag[s] = 1;
	}
}


	if(flag[0] == 1)
		cumm[0] = 1;
	for (int i = 1; str1[i] != '\0'; ++i){
		cumm[i] = cumm[i-1] + flag[i]; 
	}

	// int q;
	// cin>>q;
	// for(int i=0; i<q; i++){
	// 	int l,r;
	// 	cin>>l>>r;
	// 	l--;
	// 	r--;
	// 	if(l-1 >=0 && r-10>=0)
	// 	cout<<(cumm[r-10] - cumm[l-1])<<endl;
	// 	else if(r-10 >=0)
	// 	cout<<cumm[r-10]<<endl;
	// 	else
	// 	cout<<0<<endl;		
	// }
	int Q;
	scanf("%d",&Q);
	assert(Q<=1000000&&Q>=1);
	while(Q--){
		int l,r;
		scanf("%d",&l);
		scanf("%d",&r);
		assert(l<=r);
		l--,r--;
		if(l)
			printf( "%d\n" , cumm[r-10] - cumm[l-1]);
		else
			printf( "%d\n", (max(r-10,l-1)<0 ? 0 : cumm[max(r-10,l-1)]));		
	}
}