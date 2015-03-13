#include<iostream>
using namespace std;

int arr[10000] , nos[5];
	
int main(){
	int N , n_swaps = 0;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
		nos[arr[i]]++;
	}
	
	if(nos[1] > 0)
	while(nos[2] > 0 && nos[1] > 0){
		nos[2]--;
		nos[1]--;
		nos[3]++;
		nos[0]++;

		n_swaps++;
	}
	if(nos[1] > 0)
		while(nos[3] > 0 && nos[1] > 0){
			nos[3]--;
			nos[1]--;
			nos[4]++;
			nos[0]++;

		n_swaps++;	
		}

	if(nos[1] > 0){
		while(nos[1] > 0){
			nos[1]--;
			nos[2]++;
			nos[0]++;
		}
	}	
	cout<<nos[2]<<endl;
		int taken = 0;
	if(nos[1] > 0 && nos[4] >= 2)
		while(nos[4] > 0 && nos[1] > 0){
			if(taken % 2 == 0){
				nos[1]--;
				nos[3]++;
				nos[4] = nos[4] - 2;
				n_swaps = n_swaps + 2;
			}
			taken++;
		}	

	if(nos[2] > 0){
		while(nos[2] > 0 && nos[1] > 0)
		{
			nos[2]--;
			nos[3]++;
			nos[1]--;
			nos[0]++;
			n_swaps++;
		}
	}	
	if(nos[2] > 0){
		while(nos[2] > 0 && nos[4] > 0){
			nos[4]--;
			nos[3]++;
			nos[2]--;
		}
	}

	if(nos[1] >0 || nos[2] > 0)
	{
		n_swaps = -1;
	}	
	cout<<n_swaps<<endl;
}