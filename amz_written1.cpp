/*
Given an array of integers A[1....n-1] where 'N' is the length of array A[ ].
 Construct an array B such that B[i] = min(A[i], A[i-1], ......., A[i-K+1]), where K will be given. 
Array B will have N-K+1 elements.
*/
#include <iostream>
#include <set>
using namespace std;

set<int> tree_set;

int tree_insert(data){
	tree_set.insert(data);
}
int tree_remove(data){
	tree_set.erase(data);
}
int get_top(){

}

int main(){
int A[10000];
int B[10000];
int min_idx = 0;
for (int i = 0; i < n; ++i)
{
	cin>>A[i];
}
for (int i = 0; i < k; ++i)
{
	tree_set.push(A[i]);
}
int j=0;
B[j++] = get_top();

for (int i = k; i < n; ++i){
		tree_insert(A[i]);
		tree_remove(A[i-k]);
		B[j++] = get_top();
	}	
}