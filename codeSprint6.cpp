#include <iostream>
#include <algorithm>
using namespace std;

long long int mice[200000],holes[200000];
	
int calc(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>mice[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin>>holes[i];
	}
	sort(mice,mice+n);
	sort(holes,holes+n);

	long long int maxDis = 0,dis=0;
	for (int i = 0; i < n; ++i)
	{
		dis = abs(mice[i] - holes[i]);
		if(dis > maxDis)
			maxDis = dis;
	}
	cout<<maxDis<<endl;

	for (int i = 0; i < n; ++i)
	{
		mice[i] = 0;
		holes[i] = 0;
	}

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