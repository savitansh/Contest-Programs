#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
class Solution {

public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *head2=NULL,*tmp=NULL,*p=NULL;
		ListNode *tmp2=head;
		
		while(tmp2 != NULL && tmp2->val >= x){
			if(head2==NULL){
				head2 = tmp2;
				p = head2;
			}else{
				p->next = tmp2;
				p = tmp2;
			}
			tmp2 = tmp2->next;
		}
		if(p!=NULL)
		p->next = NULL;

		if(tmp2==NULL)
			return head2;

		head = tmp2;
		tmp = tmp2;
		tmp2 = tmp2->next;


		while(tmp2 != NULL){

			while(tmp2!=NULL && tmp2->val >= x){
				tmp->next = tmp2->next;
				
				if(head2==NULL){
					head2 = tmp2;
					p = head2;
				}else{
					p->next = tmp2;
					p = tmp2;
				}
				tmp2=tmp->next;
			}
			if(tmp->next != NULL){
			tmp = tmp->next;
			tmp2 = tmp->next;
			}
		}    
		if(p!=NULL)    
		p->next = NULL;
	
		tmp->next = head2;
		return head;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
	
		ListNode *t1=NULL,*t2=head,*t3,*t4=NULL,*t=NULL;

		for(int i=0; i<m-1 && t2!=NULL; i++){
			t1 = t2;
			t2 = t2->next;
		}
		if(t2==NULL)
			return head;

		t3 = t2->next;
		t4 = t2;
		
		for(int i=m; i<n && t3!= NULL; i++){
			t2->next = t;
			t = t2;
			t2 = t3;
			t3 = t3->next;
		}
		t2->next = t;
		if(t1 != NULL)
		t1->next = t2;
		else
			head = t2;

		t4->next = t3;

		return head;
    }

    void reorderList(ListNode *head) {
    	int len = 0;
    	ListNode *tmp=head,*old=NULL,*h2=NULL;
    	if(tmp==NULL)
    		return;
    	
    	while(tmp != NULL){
    		tmp = tmp->next;
    		len++;
    	}
    	tmp = head;
    	int n1 = len / 2;
    	if(len % 2 != 0)
    		n1++;
    	
    	h2 = reverseBetween(head,n1+1,len);
    	
    	tmp = h2;

    	head = tmp;
    	for(int i=0; i<n1-1 && tmp!=NULL; i++)
    		tmp = tmp->next;


    	h2 = tmp->next;
    	tmp->next = NULL;
    	tmp = head;

    	if(h2 != NULL)
    	old = h2->next;
		
		
    	tmp = head;    	
    	while(tmp != NULL && h2!=NULL){
    		h2->next = tmp->next;
    		tmp->next = h2;
    		tmp = h2->next;
    		h2 = old;
    		if(old != NULL)
    		old = old->next;
    	}
    	tmp = head;
    	
    }
    ListNode *h=NULL;
    TreeNode *convert(int start, int end){
    	if(start >= end)
    		return NULL;
    	
    	int mid = (start + end) / 2;
    	TreeNode *l = convert(start,mid);
    	TreeNode *r = new TreeNode(h->val);
    	r->left = l;
    	h = h->next;
    	r->right = convert(mid+1,end);
    	return r;
    }

    TreeNode *sortedListToBST(ListNode *head) {
    	if(head==NULL)
    		return NULL;

        ListNode *tmp = head;
        int len = 0;
        while(tmp != NULL){
        	tmp = tmp->next;
        	len++;
        }
        h = head;
        TreeNode *root = convert(0,len);
    }

    ListNode *rotateRight(ListNode *head, int k) {
    	if(head == NULL)
    		return NULL;

    	int len = 0;
    	ListNode *tmp=head,*tail=NULL,*old=head;

    	while(tmp != NULL){
    		tail = tmp;
    		tmp = tmp->next;
    		len++;
    	}   
    	k = k % len;
    	if(k == 0)
    		return head;

    	int d = len - k;
    	tmp = head;
    	for(int i=0; i<d-1; i++){
    		tmp = tmp->next;
    	}
    	if(tmp->next != NULL)
    	head = tmp->next;

    	tmp->next = NULL;
    	tail->next = old;
    	return head;

    }


    ListNode *deleteDuplicates(ListNode *head) {
    	ListNode *t1,*p1;
    	t1 = head;
    	if(head == NULL)
    		return NULL;

    	bool dup = false;
    	while(t1 != NULL && t1->next != NULL && t1->val == t1->next->val){
    	dup = false;
    	while(t1->next != NULL && t1->val == t1->next->val){
    		t1 = t1->next;
    		dup = true;
    	}
    	t1 = t1->next;
    	}

    	if(dup==true && t1==NULL)
    		return NULL;
		head = t1;

    	p1 = t1->next;
    	while(p1){
    		dup = false;

    		while(p1->next!= NULL &&  p1->val == p1->next->val){
    			dup = true;
    			p1 = p1->next;
    		}
    		if(dup == false){
    			t1->next = p1;
    			t1 = p1;
    		}
    			p1 = p1->next;

    	}
    	if(dup==true)
    		t1->next = NULL;

    	return head;   
    }

   
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int len1 = 0, len2 = 0;
        ListNode *t1=l1,*t2 =l2,*h3=NULL,*t3=NULL,*p=NULL;
        while(t1){
        	t1 = t1->next;
        	len1++;
        }
        while(t2){
        	t2 = t2->next;
        	len2++;
        }
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        t1 = h1;
        t2 = h2;
        
        int carry = 0,s=0;

        while(t1 && t2){
        	s=  t1->val + t2->val + carry;
        	carry = s / 10;
        	s = s % 10;
        	if(!h3){
        		h3 = new ListNode(s);
        		p = h3;
        	} else{
        		t3 = new ListNode(s);
        		p->next = t3;
        		p = t3;
        	}
        	t1 = t1->next;
        	t2 = t2->next;
        }
        
        if(t1){
        	while(t1){
        		s = t1->val + carry;
        		carry = s / 10;
        		s = s % 10;
	        		if(!h3){
	        		h3 = new ListNode(s);
	        		p = h3;
	        		} else{
	        		t3 = new ListNode(s);
	        		p->next = t3;
	        		p = t3;
	        		}	
        		t1 = t1->next;
        	}
        }else if(t2){
        	while(t2){
        		s = t2->val + carry;
        		carry = s / 10;
        		s = s % 10;
        		if(!h3){
	        		h3 = new ListNode(s);
	        		p = h3;
	        		} else{
	        		t3 = new ListNode(s);
	        		p->next = t3;
	        		p = t3;
	        		}	
        		t2 = t2->next;	
        	}
        }
        if(carry>0)
        {
        	t3 = new ListNode(carry);
        	p->next = t3;
        	p = t3;
        }

        int len = 0;
        t3 = h3;
        while(t3){
        	t3 = t3->next;
        	len++;
        }
        // h3 = reverseBetween(h3,1,len);
        return h3;
    }

    ListNode *insertionSortList(ListNode *head) {
    	ListNode *tmp = head,*p=head,*tmp2=head;
    	if(tmp2->next != NULL)
    		tmp2 = tmp2->next;
    	while(tmp){
    		tmp = tmp2;
    		p = tmp2->next;
    		while(p!=NULL && p->val>=tmp2->val){
    			old = p;
    		p = p->next;
    		}
    		if(old != NULL){
    			if(tmp2==head){
    				head = tmp2->next;
    			}
    			tmp->next = tmp2->next;
    			tmp = tmp2;
    			old->next = tmp2;
    			tmp2->next = p;
    			tmp2 = tmp->next;
    		}else
    		tmp2 = tmp2->next;
    	}   
    }
};


int traverse(TreeNode *root){
	if(root == NULL)
		return 0;
	traverse(root->left);
	cout<<root->val<<",";
	traverse(root->right);
	return 0;
}

int main(){
	Solution s;
	ListNode *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9;
	n1 = new ListNode(1);
	n2 = new ListNode(8);
	n3 = new ListNode(3);
	n4 = new ListNode(5);
	n5 = new ListNode(6);
	n6 = new ListNode(0);
	n7 = new ListNode(6);
	n8 = new ListNode(4);
	n9 = new ListNode(7);
	
	n1->next = n2;
	n2->next = NULL;//n3;
	n3->next = NULL;//n4;
	n4->next = n5;
	n5->next = NULL;
	n6->next = NULL;//n7;
	n7->next = n8;
	n8->next = NULL;//n9;
	n9->next = NULL;
	int x =3;
	
	ListNode *h = s.addTwoNumbers(n1,n6);
	while(h != NULL){
		cout<<h->val<<" ";
		h = h->next;
	}
}