#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int N  , arr[100000];

	int T;
	cin>>T;
	while(T){
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&(arr[i]));
	}

	sort(arr , arr + N);

	int stepCount = 0;
	int killCount = 0;
	bool died = false;

	for (int i = 0; i < N; ++i)
	{
		if(arr[i] - stepCount <= 0)
		{
			died = true;
			break;
		}
		stepCount++;
		killCount++;

		if(killCount % 6 == 0){
			stepCount++;
		}

	}

	if(died == true)
		cout<<"Goodbye Rick"<<endl<<killCount<<endl;
	else
		cout<<"Rick now go and save Carl and Judas"<<endl;
	
	T--;
	for (int i = 0; i < N; ++i)
		{
			arr[i] = 0;
		}	
	}
	
	return 0;
}