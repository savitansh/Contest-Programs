#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int d[103],d2[103];

int calc(string inp){
	int i=0;
	bool set = false;

	for(i=0; inp[i] != '\0'; i++){
		d[i] = inp[i]-'0';
		d2[i] = 3;
	}
	i = 0;
	int n = inp.length();
	
	if(d[0]>5)
		return -1;
	while(d[i]==5 && i<n){
		d2[i] = 5;
		i++;
		}
	if(i==n)
		return -1;

	if(d[i] > 5)
		return -1;

	while(i<n){
		if(d[i] > 5){
			int j=i-1;
			while(j>=-1 && d[j]>=5)
				j--;
			if(j!=-1)
			{
				d2[j] = 5;
				while(++j<n)
					d2[j] = 3;
				return 0;
			}
		}
		if(d[i]==5)
			d2[i]=5;

		if(d[i]>3 && d[i]<5){
			set = true;
			d2[i] = 5;
			return 0;
		}else if(d[i] < 3)
		return 0;
		i++;
	}
	if(set == false && d[n-1]==3)
		d2[n-1] = 5;
	else if(set == false){
		int k = n-1;
		while(k>=-1 && d[k]==5)
			k--;
		if(k>=-1 && d[k]==3){
			d2[k] = 5;
			while(++k<n)
				d2[k] = 3;
			return 0;
			}
			else 
				return -1;
	}
}

char inp1[103];

int main(){
	int T;
	cin>>T;
	while(T){
	
	scanf("%s",inp1);
	string inp = string(inp1);

	memset(d, 0, sizeof(int)*102);
	memset(d2, 0, sizeof(int)*102);

	int n = inp.length();
	if(calc(inp) == -1){
		for(int j=0; j<=n; j++)
			printf("3");
	}else
		for(int i=0; d2[i]!=0; i++)
			printf("%d",d2[i]);
		
		cout<<endl;

		T--;
	}	
return 0;
}