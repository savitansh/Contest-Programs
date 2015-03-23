#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	TreeNode *tail = NULL;
    void change(TreeNode *root) {
    if(root==NULL)
    return;
	if(tail==NULL)
		tail = root;
	else{
		tail->left = root;
		tail = root;
	}
    change(root->left);
    change(root->right); 
    }

    void flatten(TreeNode *root){

    	change(root);
    	TreeNode *t = root;
    	while(t){
    		t->right = t->left;
    		t = t->left;
    	}
    }

    int idx;
    TreeNode *make(int start,int end, vector<int> &inorder, vector<int> &postorder){
    	if(idx<0)
    		return NULL;

    	if(start>end)
    		return NULL;
    	int b=end;

    	int val = postorder[idx];
    	for(int i=start; i<=end; i++){
    		if(inorder[i]==val){
    			b= i;
    			break;
    		}
    	}
    	idx--;
    	TreeNode *root = new TreeNode(val);
    	root->right = make(b+1,end,inorder,postorder);
    	root->left = make(start,b-1,inorder,postorder);
    	return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        idx = postorder.size();
        idx--;
        TreeNode *root = make(0,inorder.size()-1,inorder,postorder);
        return root;
    }
};

int traverse(TreeNode *root){
	if(!root)
		return 0;
	traverse(root->left);
	cout<<root->val<<",";
	traverse(root->right);
	return 0;
}

int main(){
	TreeNode *root,*n1,*n2,*n3,*n4,*n5,*n6;
	root = new TreeNode(1);
	n1 = new TreeNode(2);
	n2 = new TreeNode(3);
	n3 = new TreeNode(4);
	n4 = new TreeNode(5);
	n5 = new TreeNode(6);
	n6 = new TreeNode(7);
	root->left = NULL;//n1;
	root->right = n4;
	n1->left = NULL;//n2;
	n1->right = NULL;//n3;
	n4->left = NULL;//n5;
	n4->right = NULL;//n6;
	Solution s;
	int ino[] = {4,2,5,1,6,3,7};
	int pos[] = {4,5,2,6,7,3,1};
	vector<int> inorder(ino,ino+7);
	vector<int> postorder(pos,pos+7);
	root = s.buildTree(inorder,postorder);
	traverse(root);
}