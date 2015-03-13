#include <iostream>
using namespace std;


	long long int tree[1000000];
int calc(){
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>tree[i];
	}

	int level = 1;
	int i = 1;
	int r = tree[1];
	int lastRight = r;
	int l = 0;
	int k = 2;
	int rightIndx = 0;
	while(i<=n){
		if(i+1 == k){
			if(lastRight > 0){
				cout<<lastRight<<endl;
				lastRight = 0;	
			}
			tree[rightIndx] = 0;
			k = k*2;
		}	
		i++;
		if(tree[i] > 0){
		lastRight = tree[i];
		rightIndx = i;	
		}
		
	}

	i = 1;
	k = 2;
	while(i<=n){
		if(i == k){
			while(tree[i] == 0 && i<(k*2))
				i++;
			if(tree[i] > 0)
				cout<<tree[i]<<endl;
			k = k*2;
		}
		i++;
	}

	for (int i = 1; i <= n; ++i)
	{
		tree[i] = 0;
	}

}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		cout<<endl;
		T--;
	}
	return 0;
}
