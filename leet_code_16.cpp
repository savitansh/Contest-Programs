#include <iostream>
#include <algorithm>
using namespace std;

int idx1,idx2;
int search(int A[1000],int B[1000], int l1,int h1, int l2, int h2){
	
	if(l1>=h1 && l2>=h2){
		idx1 = l1;
		idx2 = h2;
		return 0;
	}

	int mid1 = (l1 + h1) / 2;
	
	int mid2 = (l2 + h2) / 2;
	if(A[mid1] < B[mid2]){
		if(mid1>l1)
		search(A,B,mid1,h1,l2,mid2);
		else{
			if(A[mid1+1]<=B[mid2] && mid1+1<=h1){
				idx1 = mid1+1;
				search(A,B,mid1+1,h1,l2,mid2);
			}else{
				idx1 = mid1;
				search(A,B,mid1+1,h1,l2,mid2);
			}
		}
		}
	else if(A[mid1] > B[mid2]){
		if(mid2>l2)
		search(A,B,l1,mid1,mid2+1,h2);
		else{
			if(B[mid2]<=A[mid1]){
				idx2 = mid2;
				search(A,B,l1,mid1,mid2+1,h2);
			}
		}
	}
	else{
		idx2 = mid2;
		idx1 = mid1;
		return 0;
		}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
		
    	search(A,B,0,m-1,0,n-1);
    	double ans = 0;
    	if((m+n) % 2  == 0){
    		ans = ((double)A[idx1] + (double)B[idx2]) / 2;
    	}else
    		ans = max((double)A[idx1] , (double)B[idx2]);
    	cout<<A[idx1]<<","<<B[idx2]<<endl;    
    	return ans;
}

int main(){
	int A[1000],B[1000];
	int m,n;
	cin>>m;
	for(int i=0; i<m; i++)
		cin>>A[i];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>B[i];
	int Z[1000];
	int k=0;
	for(int i=0; i<m; i++)
		Z[k++] = A[i];
	for(int i=0; i<n; i++)
		Z[k++] = B[i];
	sort(Z,Z+(n+m));
	for(int i=0; i<m+n; i++)
		cout<<Z[i]<<",";
	cout<<endl;
	findMedianSortedArrays(A,m,B,n);
}