#include <iostream>
#include <algorithm>
using namespace std;

int M[20],V[20];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>V[i];
	for(int i=0; i<n; i++)
		cin>>M[i];

	sort(V , V+n);
	sort(M, M+n);

	int p1 = 0;
	bool flag = true;

	while(p1 < n){
		if(V[p1] < M[p1]){
			flag = false;
			break;
		}
	p1++;
	}

	if(flag == true)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}