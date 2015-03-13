/*
@author savitansh
*/
#include <iostream>
using namespace std;

char inpstr[1000000];
int inp[1000000];
	int tmp[100000];

int val[] = {1869,6189,1689,6198,1698,9861,1896};	

int count[1000000];

int main(){
	int n =0,l=0;
	cin>>inpstr;
	for (int i = 0; inpstr[i] != '\0'; ++i)
	{
		inp[i] = inpstr[i] - '0';
		if(inp[i] == 1 || inp[i] == 6 || inp[i] == 8 || inp[i] == 9)
					count[inp[i]]++;
		n++;
	}
	int mod1,t=0,j=0;
	for(int i=0; i<n; i++){

		if((inp[i] != 6 || count[6] > 1)&& (inp[i] != 1 || count[1] > 1) && (inp[i] != 8 || count[8] > 1) 
			&& (inp[i] != 9 || count[9]>1) && inp[i] != 0)
			{
				tmp[j++] = inp[i];
				if(inp[i] == 1 || inp[i] == 6 || inp[i] == 8 || inp[i] == 9)
					count[inp[i]]--;
			}
		if(inp[i] == 0)
			l++;
	}
	t = 1;
	mod1 = 0;
	for(int k=j-1; k>=0; k--){
		mod1 =  (mod1 + (tmp[k] * t) % 7) % 7;
		t = (t * 10) % 7;
	}
	//cout<<mod1<<endl;
	mod1 = (mod1 * 4) % 7;
	int remaining_mod = (7 - mod1)%7;
	for(int i=0; i<j; i++){
		cout<<tmp[i];
	}
		cout<<val[remaining_mod];
	
	for(int i=0; i<l; i++)
		cout<<0;
	cout<<endl;
}