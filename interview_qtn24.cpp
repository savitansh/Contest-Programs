#include <iostream>
using namespace std;

int main(){
	int length = 0,counter = 0;
	char G[10000],G2[10000];
	int n;
	cin>>n;

	cin>>G;
	cin>>G2;

	for(int i=0; i<n; i++){
		if((G[i] == 'R' || G[i]=='G') && length>=1){
			length++;
		}
		else if(G[i]=='.')
			length = 0;
		if((G[i] == 'R' || G[i]=='G') && length == 0){
			counter++;
			//cout<<counter<<endl;
			length = 1;
		}
		if(G[i] == 'G'){
			G[i] = 'B';
		}
	//	cout<<counter<<endl;
	}

	for(int i=0; i<n; i++){
		if((G2[i] == 'B') && length>=1){
			length++;
		}
		else if(G2[i]=='.')
			length = 0;
		if((G2[i] == 'B' ) && length == 0){
			counter++;
			//cout<<counter<<endl;
			length = 1;
		}
		
	//	cout<<counter<<endl;
	}

	cout<<counter<<endl;
}