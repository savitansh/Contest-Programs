#include <iostream>
using namespace std;

class Solution {
public:
	int find_prod(int A[], int i, int j){
		if(i > j)
			return 0;

		int neg_count =0;
		int prod = 1,prod_left=1,prod_right = 1;

		for(int k=i; k<=j; k++){
			if(A[k] < 0)
				neg_count++;
		}

		for(int k=i; k<=j; k++){
			prod = prod * A[k];
		}

		if(neg_count % 2 != 0){
			int prod1 =0,prod2 = 0,l,r;
		for(int k = i; k<=j; k++){
			if(A[k] < 0){
				l = k;
				break;
			}
		}	
		for(int k = j; k>=i; k--){
			if(A[k] < 0){
				r = k;
				break;
			}
		}

		for(int m=l+1; m<=j;m++){
			if(prod1 == 0)
				prod1 = 1;
			prod1 = prod1 * A[m];
		}
		for(int m=r-1; m>=i;m--){
			if(prod2 == 0)
				prod2 = 1;
			prod2 = prod2 * A[m];
			}
		
		prod = max(prod1,prod2);
		
		}
		return prod;
	}

    int maxProduct(int A[], int n) {
    	int j=0,i=0,m=0;
    	while(j<n){
		while(A[j] != 0 && j<n){
			j++;
		}
		j--;
		m = max(m,find_prod(A,i,j));
		//cout<<m<<endl;
		j++;
		while(A[j] == 0 && j<n)
			j++;
		i = j;
		}

		if(m == 0){
			int max1 = -1000000;
			for(int i=0; i<n; i++){
				max1 = max(max1,A[i]);
			}
			m = max1;
		}
		return m;
    }
};

int main(){
	Solution c;
	int n;
	cin>>n;
	int A[10000];

	for(int i=0; i<n; i++)
		cin>>A[i];

	cout<<c.maxProduct(A,n)<<endl;
}