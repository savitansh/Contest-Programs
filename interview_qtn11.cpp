/*
Given a sorted array, convert it into a height balanced binary search tree. 
A height balanced tree is one in which for every node, the height difference
of left and right subtree is at most 1. Node of binary tree was:

	struct node
	{
		int data;
		node* left;
		node* right;
	};
Function to be implemented was:

	node* binary_tree(int* ar, int len)
	{

	}

2. Check if given tree is BST	
*/
#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node *make_tree(int *arr, int start, int end){
	if(start>end)
		return NULL;
	struct node *root = new node();
	if(start == end){
		root->data = arr[start];
		return root;
	}

	int mid = (start + end) / 2;
	root->data = arr[mid];
	root->left = make_tree(arr, start , mid-1);
	root->right = make_tree(arr, mid+1, end);
	return root;
}

node* binary_tree(int* arr, int len)
{
	struct node *root = make_tree(arr, 0 , len-1);

	return root;
}

int max1 = 0;
bool result = true;



int inorder_traverse(node *root){
if(root==NULL)
	return 0;
inorder_traverse(root->left);
cout<<root->data<<" ";
inorder_traverse(root->right);
return 0;
}

int preorder_traverse(node *root){
if(root==NULL)
	return 0;
cout<<root->data<<" ";
preorder_traverse(root->left);
preorder_traverse(root->right);
return 0;
}
int main(){
	int arr[1000];
	int len = 0;
	cin>>len;
	for(int i=0; i<len; i++)
	cin>>arr[i];

	struct node *root = binary_tree(arr,len);
	inorder_traverse(root);
	preorder_traverse(root);	
}
