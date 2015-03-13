#include <iostream>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right,*next;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void flatten(TreeNode *root) {

    	if(root == NULL)
    		return;
    stack<TreeNode *> stk;
    	TreeNode *old = NULL,*prev = NULL,*head = NULL;
    	prev = root;
    	head = root;

    	stk.push(root);
    	while(!stk.empty()){
		if(root != NULL){
			stk.push(root);
			root = root->left;
		}else{
			root = stk.top();
			stk.pop();
			if(old == NULL){
				old = root;
				prev = root;
				}
			else{
				if(root->next == NULL)
				{	
				old->next = root;	
				old = root;
				}
			}

			root = root->right;
		}        
	}
	root = prev;

	while(root != NULL)
	{
		cout<<root->val<<" ";
		root = root->next;
	}
    }

};

int main(){
	TreeNode *root,*t1,*t2,*t3,*t4,*t5,*t6;
	root = new TreeNode(1);
	t1 = new TreeNode(2);
	t2 = new TreeNode(3);
	t3 = new TreeNode(4);
	t4 = new TreeNode(5);
	t5 = NULL;//
	t6 = new TreeNode(6);
	root->left = t1;
	root->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;
	t5->left = NULL;
	t5->right = NULL;
	Solution c;
	c.flatten(root);
	
}