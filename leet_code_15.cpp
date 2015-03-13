
 
#include <iostream>
using namespace std;

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


class Solution {
public:
	TreeLinkNode *get_next(TreeLinkNode *node){

		while(node->next != NULL){

			node = node->next;
			if(node->left != NULL)
				return node->left;
			if(node->right != NULL)
				return node->right;
		}
			return NULL;
		
	}

    void connect(TreeLinkNode *root) {
		if(root==NULL)
		return;

		if(root->left != NULL){
			if(root->right != NULL){
				root->left->next = root->right;
			}else
			root->left->next = get_next(root);
		}  	      
		if(root->right != NULL){
			root->right->next = get_next(root);
			
		}
		connect(root->left);
		connect(root->right);
    }
};

int main(){
	TreeLinkNode *root,*n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10,*n11;
	root = new TreeLinkNode(1);
	n1 = new TreeLinkNode(2);
	n2 = new TreeLinkNode(3);
	n3 = new TreeLinkNode(4);
	n4 = new TreeLinkNode(5);
	n5 = new TreeLinkNode(6);
	n6 = new TreeLinkNode(7);
	n7 = new TreeLinkNode(8);
	n8 = new TreeLinkNode(9);
	n9 = new TreeLinkNode(10);
	n10 = new TreeLinkNode(11);
	n11 = new TreeLinkNode(12);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	n3->left = n7;
	n4->left = n8;
	n4->right = n9;
	n6->left = n10;
	n6->right = n11;
	Solution s;
	s.connect(root);
	//cout<<n4->right->next->val<<endl;
}