#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	for (int i = 0; i < n; ++i)
	{
		cin>>mice[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>holes[i];
	}

	sort(mice , mice + n);
	sort(hole , hole + m);

	left = mice[0];
	right = mice[n-1];

	int i=0;
	while(hole[i] < mice[0] && (m-i) > n){
		i++;
	
	if(hole[i] > mice[0] && i > 0)
		i--;

	max1 = 0;
	for(int j=0; j<n; j++){
		d = abs(mice[j] - hole[i]);
		if(d > max1)
			max1 = d;
		i++;
	}

}