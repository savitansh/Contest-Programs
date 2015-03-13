#include <iostream>
using namespace std;

struct swaps{
	int i1,i2;
}swaps[10000];

int arr[10000];

int swap(int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int main(){
	int n,swap_count=0,m=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int min1 = 10000;
		for(int j=i; j<n; j++){
			if(arr[j] < min1){
				min1 = arr[j];
				m = j;
			}
		}
		if(m != i){
			swap(i,m);
				swaps[swap_count].i1 = i;
				swaps[swap_count].i2 = m;
				swap_count++;
		}


	}

	cout<<swap_count<<endl;
	for (int i = 0; i < swap_count; ++i)
	{
		cout<<swaps[i].i1<<" "<<swaps[i].i2<<endl;
	}
}