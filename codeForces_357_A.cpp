#include<iostream>
using namespace std;

	int students[100000],sum[100000];

int main(){
	int N;
	cin>>N;
	

	for (int i = 0; i < N; ++i)
	{
		cin>>students[i];
		sum[i] = 0;
	}

	int x,y,k=0;
	cin>>x>>y;

	sum[0] = students[0];

	for (int i = 1; i < N; ++i)
	{
		sum[i] = sum[i-1] + students[i];
		
	}

	bool found = false;
	for (int i = 0; i < N; ++i)
	{
		
		if(sum[i]>=x && sum[i]<=y && (sum[N-1] - sum[i]) >=x && (sum[N-1] - sum[i]) <= y)
			{
				k = i+1;
				found = true;
				break;
			}
	}
	if(found == true)
	cout<<(k+1)<<endl;
	else
	cout<<0<<endl;	
}