#include <iostream>
using namespace std;

int mat[1000][1000];
int m2[1001];	
int main(){
	int T;
	cin>>T;
	int t = 1;
	while(t<=T){

	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>mat[i][j];
		}
	}
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		if(i+1<n  && mat[i+1][j] == mat[i][j]-1){
			m2[mat[i][j]] = 1;
			//cout<<mat[i][j]<<endl;
		}
		if(i-1>=0  && mat[i-1][j] == mat[i][j]-1){
			m2[mat[i][j]] = 1;
			//cout<<mat[i][j]<<endl;
		}
		if(j+1<n  && mat[i][j+1] == mat[i][j]-1){
			m2[mat[i][j]] = 1;
			//cout<<mat[i][j]<<endl;
		}
		if(j>=0  && mat[i][j-1] == mat[i][j]-1){
			m2[mat[i][j]] = 1;
			//cout<<mat[i][j]<<endl;
		}
	}
	}

int counter = 0;
int maxCount = 0,winner= 0,start = 0;
m2[1] = 0;
	// for(int j=1; j<10; j++){
	// 	cout<<m2[j];
	// }
	// cout<<endl;

for(int i=0; i<1000; i++){
		if(m2[i] == 1){
			counter++;
			if(counter == 1){
				start = i;
			}
//			cout<<counter<<endl;
			if(counter > maxCount){
				maxCount = counter;
				winner = start;
			}
		}else
		counter = 0;
	}
if(winner == 0)
	winner = 2;
cout<<"Case #"<<t<<": "<<winner-1<<" "<<maxCount+1<<endl;

	for (int i = 0; i < 1000; ++i)
	{
		for(int j=0;j<1000; j++)
			mat[i][j] = 0;
	}
	for (int i = 0; i < 1000; ++i)
	{
		m2[i] = 0;
	}
t++;

}

}