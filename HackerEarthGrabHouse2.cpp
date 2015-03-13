#include <iostream>
#include <vector>
using namespace std;

int ch;
int better[1200][1200];

int tourn(vector<int> prev){
	int sz = prev.size();

	if(sz <=2){
		int p1 = prev[0];
		int p2 = prev[1];
		if(p1>p2){
			int t = p1;
			p1 = p2;
			p2 = t;
		}
		
		if(better[p2][p1] == 1)
		ch = p2;
		else
		ch = p1;	
		return 0;
	}

	vector<int> winners;
	
	
	for(int i=0; i<sz-1; i = i+2){
		int p1 = prev[i];
		int p2 = prev[i+1];
		if(p1>p2){
			int t = p1;
			p1 = p2;
			p2 = t;
		}

		if(better[p2][p1] == 1)
			winners.push_back(p2);
			else
			winners.push_back(p1);	
		
	}
	if(sz %2 != 0)
	{
		winners.push_back(prev[sz-1]);
	}
	tourn(winners);
}

int main(){
	int n;
	cin>>n;
	vector<int> winners;
	int players = (2<<n-1)-1;
	
	winners.push_back(1);

	for(int i=1; i<=players; i++){
		for(int j=1; j<=i; j++){
			int k;
			cin>>k;
			better[i+1][j] = k;
			}
		winners.push_back(i+1);
	}
	tourn(winners);
	cout<<ch<<endl;
}