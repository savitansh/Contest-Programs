/*
@author savitansh
1. find inorder succesor in BST
2. Remove all leaves recursively with given value
3. trim bst whose nodes don't lie in range(min,max)
4. print all siblings of a node
5. BST to DLL
6. Diameter of tree with atmost one turn
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct tree{
	int data;
	struct tree *lc,*rc,*parent,*next,*prev;
}*root,*root1,*root2;



int inorder_successor(struct tree *node,struct tree *toFind){
	if(node == NULL)
		return 0;
	if(node == toFind){
		struct tree *node2 = node;
		if(node->rc != NULL){
			node2 = node2->rc;
			while(node2->lc != NULL)
				node2 = node2->lc;
			cout<<node2->data<<endl;
		}else
		return 1;
	}
	int val = inorder_successor(node->lc, toFind);
	if(val == 1){
		cout<<node->data<<endl;
		return 0;
	}
	int val2 = inorder_successor(node->rc,  toFind);
	return max(val,val2); 
}

int inorder_traversal(struct tree *root){
	if(root == NULL)
		return 0;
	inorder_traversal(root->lc);
	cout<<root->data<<" ";
	inorder_traversal(root->rc);
	return 0;
}


int delete_leaf(int val, struct tree *node){
	if(node == NULL)
		return 0;
	delete(val, node->lc);
	delete(val, node->rc);
	if(node->data == val && node->lc==NULL && node->rc==NULL)
		node = NULL;
	return 0;
}

int max1 = 0;
bool result=true;
int check_BST(tree *root){
if(root == NULL)
	return result;
check_BST(root->lc);
if(root->data >= max1)
max1 = root->data;
else
result = false;
check_BST(root->rc);
return result;
}

int dia(tree *node, int turn, bool turned){
	if(node == NULL)
		return 0;

	if(turn == 0 && turned==false){
		return max(dia(node->left,false),dia(node->right,true),dia(node->left,true)+dia(node->right,true)) + 1;
	}else if(turn == 1 && turned==false){
		return(max(dia(node->right,false)),dia(node->left,true)) + 2;
	}else if(turn == 0 && turned==true)
	return dia(node->left,true)+1;
	else if(turn==1 && turned==true)
		return dia(node->right,true)+1;
}
/*
tree *trim(int min1, int max1, Tree *node){
	if(node == NULL)
		return;
	Tree *node1 = trim(min1, max1, node->lc);
	Tree *node2 = trim(min1, max1, node->rc);
	if(node->data > max1 || node->data < min1)
	{
		node = NULL;
		if(node1 != NULL)
			return node1;
		else if(node2 != NULL)
			return node2;
	}	
	else{
		node->lc = node1;
		node->rc= node2;
	}
	return node;
}
*/
int intersection(tree *root1, tree *root2){
	stack<tree *> stk1,stk2;
	stk1.push(root1);
	stk2.push(root2);
	while(!stk1.empty() && !stk2.empty()){
		if(root1!=NULL){
			stk1.push(root1);
			root1 = root1->lc;
		}
		else if(root2!=NULL){
			stk2.push(root2);
			root2 = root2->lc;
		}
		else{
			root1 = stk1.top();
			root2 = stk2.top();
			if(root1->data < root2->data){
				stk1.pop();
				root1->lc = NULL;
				root2 = NULL;
				root1 = root1->rc;
			}else if(root1->data > root2->data){
				stk2.pop();
				root2->lc = NULL;
				root1 = NULL;
				root2 = root2->rc;
			}else{
				cout<<root1->data;
				stk1.pop();
				root1->lc = NULL;
				root1 = root1->rc;
			}
			
		}
	}
}

struct tree *get_node(struct tree *root, int val){
	while(1){
		if(root == NULL)
			return NULL;

		if(val > root->data){
			if(root->rc != NULL)
				root = root->rc;
			else
				return root;	
		}else if(val < root->data){
			if(root->lc != NULL)
				root = root->lc;
			else
				return root;
		}
		else
			return root;
	}
}

vector<int> siblings;
vector<int>::iterator it;

int find_siblings(tree *node, int level){
	if(node == NULL)
		return 0;

	if(level==0){
		siblings.push_back(node->data);
		return 0;
	}
	find_siblings(node->lc, level-1);
	find_siblings(node->rc, level-1);
	return 0;
}
//Prints right siblings of a node
int print_siblings(tree *node){
	int level = 0;
	tree *old = node;
	while(node->parent != NULL){
		level++;
		node = node->parent;
	}
	find_siblings(node,level);
	for(it = siblings.begin(); it!= siblings.end(); it++){
		if(*it == old->data){
			break;
		}
	}
	it++;
	while(it != siblings.end()){
		cout<<*it<<" ";
		it++;
	}
	return 0;
}


	/*--------------| Convert BST to DLL |------------------*/
tree *tail = NULL;
int add_to_list(tree *node){
	if(tail == NULL){
		tail = node;
		tail->next = NULL;
		tail->prev = NULL;
		return 0;
	}
		
	tail->next = node;
	node->prev = tail;
	tail = node;
	return 0;
}

int bst_to_dll(tree *node){
	if(node == NULL)
		return 0;

	bst_to_dll(node->lc);
	add_to_list(node);
	bst_to_dll(node->rc);

	return 0;
}

int main(){

	int n;
	int arr[10000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

struct tree *node;
root1 = new tree();
root1->data = arr[0];

	for(int i=1; i<n; i++){

		struct tree *to_insert = get_node(root1, arr[i]);
			 node = new tree();
			 node->data = arr[i];
			 if(arr[i] >= to_insert->data)
			 	to_insert->rc = node;
			else
				to_insert->lc = node;
			node->lc = NULL;
			node->rc = NULL;
			node->parent = to_insert;
	}	
	
	// cin>>n;
	// for(int i=0; i<n; i++){
	// 	cin>>arr[i];
	//	}

// root2 = new tree();
// root2->data = arr[0];

// 	for(int i=1; i<n; i++){
// 		struct tree *to_insert = get_node(root2, arr[i]);
// 			node = new tree();
// 			node->data = arr[i];
// 			if(arr[i] >= to_insert->data)
// 				to_insert->rc = node;
// 			else
// 				to_insert->lc = node;
// 			node->lc = NULL;
// 			node->rc = NULL;
// 			node->parent = to_insert;
// 	}

	//intersection(root1, root2); 
	//inorder_traversal(root);	
	//inorder_successor(root,root);
	//cout<<successor->data<<endl;
	//print_siblings(root1->lc->lc);
//	bst_to_dll(root1);
	//cout<<"ok";

}