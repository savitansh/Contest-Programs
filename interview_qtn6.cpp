/*
find element in sorted rotated array
*/
#include <iostream>
using namespace std;

int arr[10000];
int n;

int locate_rotation_pt(){
	int mid = 0,low=1,high=n,point=0;

	while(1){
		if(low > high)
			break;
	mid = (low + high) / 2;	
	if(arr[mid] > arr[mid+1]){
		point = mid;
		break;
	}else if(arr[mid-1] > arr[mid]){
		point = mid-1;
		break;
	}	
	if(arr[mid] < arr[low])
		high = mid-1;
	if(arr[mid] > arr[low])
		low = mid+1;	
	}
	if(point == n)
		return 0;
	return point;
}

bool binary_search(int low, int high, int val){
	int mid = 0;
	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] == val)
			return true;
		if(arr[mid] < val){
			low = mid+1;
		}else if(arr[mid] > val){
			high = mid-1;
		}
	}
	return false;
}

bool search(int val, int point){
	int low = 1, high = n;
if(arr[high] < val){
	high = point;
	}else if(arr[low] > val){
		low = point+1;
	}

	bool flag = binary_search(low, high, val);
	return flag;
}

int main(){
	int val = 0;
	cin>>n>>val;
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	int point =	locate_rotation_pt();
	bool result = search(val, point);
	cout<<result<<endl;

	return 0;
}