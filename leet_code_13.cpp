/*
@author savitansh
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int bin_search(int A[],int low,int high,int target){
		
		while(low <= high){
			int mid = (low + high) / 2;
			if(A[mid] == target)
				return mid;
			else if(A[mid] < target)
				low = mid+1;
			else
				high = mid-1;
		}
		return -1;
	}

    int search(int A[], int n, int target) {
    	if(n==0)
    		return -1;
    	if(n<2)
    	{
    		if(A[0]==target)
    			return 0;
    		return -1;
    	}

		int pivot = n-1;
		int low = 0,high = n-1,mid=0;
		while(low <= high){
			mid = (low + high) / 2;
			if(mid+1<=high && A[mid+1]<A[mid]){
				pivot = mid;
				break;
			}
			else if(A[mid]<A[mid+1] && A[low] > A[high] && A[mid] > A[high]){
				low = mid+1;
			}else if(A[mid]<A[mid+1] &&  A[low] > A[high] && A[mid] < A[low]){
				high = mid;
			}else if(A[low]<=A[high])
				low = mid+1;
		}	   
		//cout<<pivot<<endl;
		low = 0,high = n-1;   
		if(target>=A[low] && target <= A[pivot]){
			high = pivot;
		}else{
			low = pivot+1;
			high = n-1;
		}
		return bin_search(A,low,high,target);
    }
};

int main(){
	Solution s;
	int target,n;
	int A[1000];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>A[i];
	cin>>target;
	int pos = s.search(A,n,target);
	cout<<pos<<endl;
}