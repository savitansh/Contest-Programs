/* Union find and path compression */

#include<iostream>
using namespace std;

int nextAlive[100000],defeated[100000];

int init(int N){
for(int i=0; i<=N; i++)
	nextAlive[i] = i;
}

int findAlive( int x){
	if(nextAlive[x] == x)
		return x;
	nextAlive[x] = findAlive(nextAlive[x]);
	return nextAlive[x];
}

int makeAns(int l , int r , int x){
	int curr = l;
	curr = findAlive(l);
	while(curr <= r){
	if(curr != x)
	{
		defeated[curr] = x;
		nextAlive[curr] = curr + 1;
	}	else {
		curr = curr + 1;
	}
	curr = findAlive(curr);
	}

}

int main(){
	int N,l,r,m,x,winner;
	cin>>N;
	cin>>m;
	
	init(N);
	for(int i=0; i<m; i++){
		cin>>l>>r>>x;
		makeAns(l-1,r-1,x-1);
		winner = x;
	}

	for (int i = 0; i < N; ++i)
	{
		if(i+1 != winner)
		cout<<defeated[i]+1<<" ";
		else
		cout<<0;	
	}
	cout<<endl;
}
