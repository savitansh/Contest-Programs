/*
sort a 2d sorted matrix to 1d
*/
#include <iostream>
using namespace std;

struct heap{
	int val,row;
	int heap_size;
	int extract_min();
	int push(int val);
	int build(int *arr, int n);
}heap_node[10000];

int heap::build(int arr[10000], int n){
	for(int i=0; i<n; i++){
		heap_node[i].val = arr[i];
		heap_node[i].row = i;
	}
	heap_size = n;

	for(int i=n-1; i>=1; i--){
		if(heap_node[i].val < heap_node[i/2].val){
			int t = heap_node[i].val;
			heap_node[i].val = heap_node[i/2].val;
			heap_node[i/2].val = t;
		}
	}
}

int heap::push(int val){
	heap_size++;
	int t = heap_node[0].val;
	heap_node[0].val = val;
	heap_node[heap_size-1].val = t;

	int h = heap_size-1;
	while(h>0 && heap_node[h].val < heap_node[h/2].val){
		t = heap_node[h].val;
		heap_node[h].val = heap_node[h/2].val;
		heap_node[h/2].val = t;
		h = h/2;		
	}
	return 0;
}

int heap::extract_min(){
	int top = heap_node[0].row;

	heap_node[0].val = heap_node[heap_size-1].val;
	heap_node[0].row = heap_node[heap_size-1].row;
	heap_node[heap_size-1].val = 0;
	heap_node[heap_size-1].row = 0;
	heap_size--;
	return top;
}

int main(){
	int arr[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	}
	int t[1000];
	int c = 0;
	while(c<n*n){
		
	}
}