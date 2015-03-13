#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
bool filled[1000000];

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int p1=0,p2=0;
	sort(arr,arr+n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	while(p2 < n)
	{
		if(arr[p1] == -1)
		p1++;
		if(p1 > p2)
		p2 = p1;	

		if(arr[p1] > (arr[p2]/2)){
			p2++;
		}else if(arr[p1]*2 <= arr[p2] && filled[p2] != true){
			arr[p1] = -1;
			p1++;
			filled[p2] = true;
		}else if(filled[p2] == true){
			p2++;
		}
	}

	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] == -1)
			counter++;
	}

	int total = n - (counter);
	cout<<total<<endl;
}
