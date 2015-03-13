/* Bit hack lexico sequence for bit string with fixed no of ones */

#include<iostream>
using namespace std;

int generateNo(int n){
	long long int v = 1;
	v = v<<(n);

	v--;
	return v;
}

int getPath(int path[100] , long long int w){

	int i = 0;
	while(w > 0)
	{
		if(w & 1 == 1)
			path[i] = 1;
		else
			path[i] = 0;
		w = w>>1;
		i++;
	}
	return 0;
}

	int path[100];
int calc(){
	int n=0,m=0 , k=0;
	cin>>n>>m>>k;
	
	int ones = n;
	long long int v = generateNo(ones);
	long long int t=0,w=0;
	int indx = 1;
	
		for (int i = 20; i >= 0; i--)
		{
			path[i] = 0;
		}

		if(k == 0){
		for (int i = 0; i < m; ++i)
		{
			cout<<'H';
		}	
		for (int i = m; i <= m+n-1; ++i)
		{
			cout<<'V';
		}		
		}	else {
			while(indx <= k){
				 t = (v | (v-1)) + 1;
				w = t | ( (((t & -t) / (v & -v)) >> 1) -1 );
				v = w;
				indx++;
			}
			
				if(k>0)
				getPath(path,w);

			
			for (int i = n+m-1; i >= 0; i--)
			{
				if(path[i] == 0)
					cout<<'H';
				else
					cout<<'V';
			}
			
		
		}
		

		cout<<endl;
	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}