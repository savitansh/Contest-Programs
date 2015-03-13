#include <iostream>
using namespace std;


	int arr[100];
	
int calc(){
	int N;
	int total = 0,count=0;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
		total = total + arr[i];
	}
	int avg1 = total / N;
	
	for (int i = 0; i < N; ++i)
	{
		if(arr[i] > avg1)
			count++;
	}
	cout<<count<<endl;
	for (int i = 0; i < N; ++i)
	{
		arr[i] = 0;
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