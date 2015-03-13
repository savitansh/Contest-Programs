#include <iostream>
#include <algorithm>
using namespace std;

	int data[100000],cumm[100000];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i)
	{
		cin>>data[i];
	}

	int tail = 1,head = m;

	int s = 0;
	for(int i=tail; i<=head; i++){
		s = s + data[i];
	}
	cumm[1] = s;
	tail++;
	head++;
	
	while(head<=n){
		int s = cumm[tail-1] + data[head] - data[tail-1];
		cumm[tail] = s;		
		tail++;
		head++;
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<cumm[i]<<" ";
		cumm[i] = -cumm[i];
	}

	sort(cumm+1 , cumm + n+1);

	for (int i = 0; i < n; ++i)
	{
		cumm[i] = -cumm[i];
	}

	int ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans = ans + cumm[i];
	}
	
	cout<<ans<<endl;

}