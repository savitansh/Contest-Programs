#include <iostream>
using namespace std;

int boy[101],girl[101];

int main(){
	int n,m,b,g,h,count=0;
	cin>>n>>m;
	cin>>b;
	for(int i=0; i<b; i++){
		cin>>h;
		boy[h] = 1;
		count++;
	}
	cin>>g;
	for(int i=0; i<g; i++){
		cin>>h;
		girl[h] = 1;
		count++;
	}

	int d = (n+1)*(m+1)+2;
	for(int i=0; i<d; i++){
		if(boy[i%n] || girl[i%m]){
			if(boy[i%n] == 0){
				boy[i%n] = 1;
				count++;
			}else if(girl[i%m]==0){
				girl[i%m] = 1;
				count++;
			}
		}
		if(count >= n+m){
			cout<<"Yes"<<endl;
			break;
		}
	}
	if(count<n+m)
		cout<<"No"<<endl;
	return 0;
}