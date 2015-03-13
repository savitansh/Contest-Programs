#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	int max_sum;

	int update_sum(TreeNode *root){
		if(root == NULL)
    		return 0;

     	int ans1 = max(0,update_sum(root->left));
     	int ans2 = max(0,update_sum(root->right));
     	int ans = ans1 + ans2 + root->val;
     	
     	if(ans > max_sum)
     	max_sum = ans;
     	return (max(ans1,ans2) + root->val);
	}

    int maxPathSum(TreeNode *root) {
    	max_sum = -1000000;
    	update_sum(root);
    	return max_sum;		
    }
};

int main(){
	Solution s;
	TreeNode *root,*n1,*n2,*n3,*n4,*n5,*n6;
	root = new TreeNode(-3);
	n1 = new TreeNode(2);
	n2 = new TreeNode(10);
	n3 = new TreeNode(3);
	n4 = new TreeNode(7);
	n5 = new TreeNode(6);
	n6 = new TreeNode(-4);
	

	root->left = NULL;
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->right = n6;


	cout<<s.maxPathSum(root)<<endl;
}