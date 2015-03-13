/*
BST to DLL
*/
#include <iostream>
using namespace std;

struct treeNode{
	int data;
	treeNode(int val){
		data = val;
	}
	treeNode *left=NULL, *right=NULL;
}*root,*head,*tail;

int convert(treeNode *node){
	if(node == NULL)
		return 0;
	
	convert(node->left);
	if(head == NULL)
		head = node;
	if(tail != NULL){
	node->left = tail;
	tail->right = node;
	tail = node;
	}else
	tail = node;

	convert(node->right);
	return 0;
}

int print_list(treeNode *ptr){
	treeNode *tmp = ptr;
	while(tmp != NULL){
		cout<<tmp->data<<" ";
		tmp = tmp->left;
	}
	return 0;
}

int print_path(treeNode *root){
	for(int i=0; i<top; i++){
		cout<<(stk[i])->data<<" ";
	}
	cout<<root->data<<endl;
}

int push_back(treeNode *root){
	stk[top] = root;
	top++;
}

treeNode *pop(){
	if(top<0)
		return NULL;

	treeNode *node = stk[top];
	top--;
	return node;
}

int root_leaf_path(treeNode *root){
	stk.push_back(root);
	while(!stk.empty()){
		if(root != NULL){
			push_back(root);
			root = root->left;
		}else{
			root = pop();
			if(isleaf(root)){
				
				print_path(root);
			}else if(root != NULL)
			push_back(root);
			
			root = root->right;
		}
	}
}

int main(){
	treeNode *root,*n1,*n2,*n3,*n4;
	root = new treeNode(1);
	n1 = new treeNode(2);
	n2 = new treeNode(3);
	n3 = new treeNode(4);
	n4 = new treeNode(5);
	root->left = NULL;
	root->right = n1;
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	convert(root);
	print_list(tail);

	return 0;
}