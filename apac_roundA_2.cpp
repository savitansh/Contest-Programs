/*
@author savitansh
*/
#include <iostream>
#include <string.h>
using namespace std;


int list[20];
int swap(int p1, int p2){
	int tmp = list[p1];
	list[p1] = list[p2];
	list[p2] = tmp;
}

int shift(int n){
	int p1 = 0, p2 = 1;

	while(p1 < n){
		if(list[p1] == 0)
			break;
		p1++;
	}
	p2 = p1 + 1;
	while(p2 < n){
		if(list[p2] != 0 && list[p1] == 0){
			swap(p1, p2);
			p1++;
			p2++;
		}else
		p2++;
	}
}
int merge(int n){
	int p1 = 0,p2 = 1;
	while(1){
		if(p2 >= n)
			break;
		if(list[p2] == 0)
			{
			while(list[p2] == 0 && p2 < n){
					p2++;
				}	
			}
		if(list[p1] == 0)
			{
				while(list[p1] == 0 && p1 < n){
					p1++;
				}
				p2 = p1 + 1;
			}
		if(list[p1] == list[p2] && list[p1] != 0 && list[p2] != 0 ){
			list[p1] = list[p1] + list[p2];
			list[p2] = 0;
			p2++;
			p1++;
		}	
		else if(list[p1] != list[p2] && list[p1] != 0 && list[p2] != 0){
			p1++;
			p2++;
		}
		
	}

	shift(n);

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<list[i];
	// }
}

int calc(int t){
	int n,k=0;
	cin>>n;

	char choice[20];
	cin>>choice;

	int mat[20][20];
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<n; j++){
			cin>>mat[i][j];
		}
	}

	if(strcmp(choice,"left") == 0){
		for (int i = 0; i < n; ++i)
		{
			k = 0;
			for(int j=0; j<=n; j++){
				list[k++] = mat[i][j];
			}
		merge(n);
			k = 0;
			for(int j=0; j<=n; j++){
				mat[i][j] = list[k++];
			}
		}
	}	else if(strcmp(choice,"right") == 0){
		for (int i = 0; i < n; ++i)
		{
			k = 0;
			for(int j=n-1; j>=0; j--){
				list[k++] = mat[i][j];
			}
		merge(n);
			k = 0;
			for(int j=n-1; j>=0; j--){
				mat[i][j] = list[k++];
			}
		}
	}	else if(strcmp(choice,"up") == 0){
		for (int i = 0; i < n; ++i)
		{
			k = 0;
			for(int j=0; j<=n; j++){
				list[k++] = mat[j][i];
			}
		merge(n);
			k = 0;
			for(int j=0; j<=n; j++){
				mat[j][i] = list[k++];
			}
		}
	}	else if(strcmp(choice,"down") == 0){
		for (int i = 0; i < n; ++i)
		{
			k = 0;
			for(int j=n-1; j>=0; j--){
				list[k++] = mat[j][i];
			}
		merge(n);
			k = 0;
			for(int j=n-1; j>=0; j--){
				mat[j][i] = list[k++];
			}
		}
	}
	
	cout<<"Case #"<<t<<":"<<endl;	
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}


int main(){
	int T;
	cin>>T;
	int t = 1;
	while(t<=T){
		calc(t);
		t++;
	}
	return 0;
}