/*
find index containing 0 to flip which makes longest contigous subarray of 1s 
*/
#include <iostream>
using namespace std;

int calc(int arr[10000], int n){
	int p1 = 0, p2 = 0,count = 0,max_len=0,m;

	while(p2 < n){
		if(arr[p2] == 0){
			count++;
			if(count > 1)
			{
				while(arr[p1] == 1 && p1 < p2)
					p1++;
				if(arr[p1] == 0 && p1<p2){
					p1++;
					count--;
				}else if(p1 == p2)
				count--;
			}
		}
		if(p2-p1+1 > max_len){
			max_len = (p2-p1+1);
			m = p1;
		}
		p2++;
	}

	cout<<max_len<<endl;
		
	while(arr[p1] == 1 && p1<n){
		p1++;
	}
	if(arr[p1] == 0 && p1<n)
		return p1;
	return -1;
}

int main(){
	int arr[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<calc(arr,n)<<endl;

}