#include <iostream>
#include <algorithm>
using namespace std;

int min1 = 10000000;
int arr[102];
int n=0;
int find_max(int a,int b, int c){
	int max1 = 0;
	max1 = max(a,b);
	max1 = max(max1,c);
	return max1;
}

int fun(int indx, int i, int s1, int s2, int s3){
	if(indx == n){
		min1 = min(min1, find_max(s1,s2,s3));
		return 0;
	}
	//cout<<indx<<" : "<<s1<<" "<<s2<<" "<<s3<<endl;
	if(i==0){
		s1 += arr[indx];
	}else if(i==1){
		s2 += arr[indx];
	}else if(i=2){
		s3 += arr[indx];
	}

	fun(indx+1, 0,s1,s2,s3);
	fun(indx+1, 1,s1,s2,s3);
	fun(indx+1, 2,s1,s2,s3);

	return 0;
}


int main(){
	int s1=0,s2=0,s3=0;

	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	fun(0,0,s1,s2,s3);
	fun(0,1,s1,s2,s3);
	fun(0,2,s1,s2,s3);

	cout<<min1<<endl;

	return 0;
}