/*
@author savitansh
*/
#include <iostream>
#define MOD 1000000007
using namespace std;

long long int arr[1000000];

int n=0;

bool check(long long int botEnergy){
	for(int i=0; i<n; i++){
	botEnergy = (botEnergy - (arr[i+1] - botEnergy)) % MOD;
	if(botEnergy < 0)
		return false;
	}
	return true;
}

long long int low=1, high=100000000,init_enrgy=0,ans=0;

int main(){
	
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>arr[i];
	}
	
	for(long long int l=1; l<=10000000;l++){
		if(check(l) == true){
			ans = l;
			break;
		}
	}
	// while(low <= high){
	// 	init_enrgy = (low + high)/2;
	// 	if(check(init_enrgy)==true && check(init_enrgy-1)==true){
	// 		high = init_enrgy-1;
	// 	}else if(check(init_enrgy)==false )
	// 	low = init_enrgy+1;
	// 	else if(check(init_enrgy)==true && check(init_enrgy-1)==false){
	// 		ans= init_enrgy;
	// 		//cout<<ans<<endl;
	// 		break;
	// 	}	
	// }

	cout<<ans<<endl;
}