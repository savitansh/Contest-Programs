#include <iostream>
#include <algorithm>
using namespace std;

int b[101],g[101];

int main(){
	int n1,n2,total_count=0;
	cin>>n1;
	for (int i = 0; i < n1; ++i)
	{
		cin>>b[i];
	}
	cin>>n2;
	for (int i = 0; i < n2; ++i)
	{
		cin>>g[i];
	}

	sort(b,b+n1);
	sort(g,g+n2);

	int p1=0,p2=0;
	while(p1<n1 && p2<n2){
		if(abs(b[p1] - g[p2]) <= 1){
				//cout<<b[p1]<<":"<<g[p2]<<endl;
			total_count++;
			p1++;
			p2++;
		}
		else{
			if(b[p1] <= g[p2]){
			p1++;
			}else{
				p2++;
			}
		}
	}

	cout<<total_count<<endl;
}