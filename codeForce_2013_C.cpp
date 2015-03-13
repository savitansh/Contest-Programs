#include <iostream>
#include <algorithm>
using namespace std;

struct data{
	long long int val;
	int idx;
}arr[500000];

//long long int arr[500000];
bool comparator(const struct data &a, const struct data &b){
	return a.val < b.val;
}
bool comparator2(const struct data &a, const struct data &b){
	return a.idx < b.idx;
}
int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].val;
		arr[i].idx = i;
	}
	sort(arr,arr+n,comparator);
	for (int i = 1; i < n; ++i)
	{
		if(arr[i].val <= arr[i-1].val)
			arr[i].val = arr[i-1].val +1;
	}
	sort(arr, arr+n, comparator2);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i].val<<" ";
	}
	cout<<endl;
}