#include <iostream>
using namespace std;

struct treeNode{
	int val;
	treeNode *left,*right;
	treeNode(int x){
		val = x;
		left = NULL;
		right = NULL;
	}
};

int preorder[100],inorder[100];
int curr;

struct treeNode *create(int start, int end){
	if(start>end)
		return NULL;

	if(start==end){
		treeNode *node = new treeNode(inorder[start]);
		node->left = node->right = NULL;
		return node;
	}
	
	for(int i=start; i<=end; i++){
		if(preorder[curr]==inorder[i]){
			treeNode *node = new treeNode(inorder[i]);
			curr++;
			node->left = create(start,i-1);
			node->right = create(i+1,end);
			return node;
		}
	}
	return NULL;
}

int main(){
	curr = 0;
}