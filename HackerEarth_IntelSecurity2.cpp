#include <iostream>
#include <algorithm>
using namespace std;

struct guest{
	long long int arrival;
	long long int departure;
}g[100000];

bool comp(const struct guest &g1 , const struct guest &g2){
	if(g1.departure < g2.departure){
		return 1;
	}
	if(g1.departure == g2.departure && g1.arrival <= g2.arrival)
		return 1;

	return 0;
}

int calc(){
	int n;
	long long int arr,dur;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr;
		g[i].arrival = arr;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>dur;
		g[i].departure = g[i].arrival + dur;
	}
	
		
	sort(g ,g + n , comp);

	long long int minArr  = g[0].arrival;
	long long int minDep = g[0].departure;
	int di = 0;
	int hotels = 1;
	int maxHotels = 0;
	
	for (int i = 1; i < n; ++i)
	{
	//	cout<<minArr<<":"<<minDep<<":"<<hotels<<endl;
		if(g[i].arrival < minDep)
		{
			hotels++;
			if(hotels > maxHotels)
				maxHotels = hotels;
			minArr = max(g[i].arrival , minArr);
			minDep = min(g[i].departure , minDep);
		}
		else if(g[i].arrival >= minDep){

			minArr = g[i].arrival;
			while(g[di].departure <= minDep || g[di].departure <= g[i].arrival)
			{
				di++;
				hotels--;
			}
			minDep = g[di].departure;
			hotels++;
		}
	}
	cout<<hotels<<endl;

	for (int i = 0; i < n; ++i)
	{
		g[i].arrival = 0;
		g[i].departure = 0;
	}
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