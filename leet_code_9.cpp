
#include <iostream>
#include <vector>
using namespace std;

 //* Definition for singly-linked list with a random pointer.
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL)
    		return NULL;
    	
    	RandomListNode *tmp2,*p,*head2,*tmp = head;
    	vector<RandomListNode *> node_list;

    	p = new RandomListNode(tmp->label);
    	p->next = NULL;
    	head2 = p;
    	node_list.push_back(tmp->random);
    	p->random = tmp->random;
    	tmp->random = p;
    	tmp = tmp->next;

    	while(tmp != NULL){
    		tmp2 = new RandomListNode(tmp->label);
    		p->next = tmp2;
    		p = tmp2;
    		tmp2->next = NULL;
    		node_list.push_back(tmp->random);
    		tmp2->random = tmp->random;
    		tmp->random = tmp2;
    		tmp = tmp->next;
    	}

    	tmp2 = head2;
    	while(tmp2 != NULL){
    		tmp2->random = tmp2->random->random;
    		tmp2 = tmp2->next;
    	}
    	tmp = head;
    	vector<RandomListNode *>::iterator it;
    	it = node_list.begin();
    	while(tmp != NULL){
    		tmp->random = *it;
    		it++;
    		tmp = tmp->next;
    	}
    	return head2;
    }
};

int main(){
	RandomListNode *h,*t,*t2,*t3,*t4;
	h = new RandomListNode(1);
	t = new RandomListNode(2);
	h->next = t;
	t2 = new RandomListNode(3);
	t3 = new RandomListNode(4);
	t4 = new RandomListNode(5);
	t->next = t2;
	t2->next = t3;
	t3->next = t4;
	h->random = t3;
	t->random = t;
	t2->random = t3;
	t3->random = h;
	t4->random = t2;
	Solution c;
	RandomListNode *cpy = c.copyRandomList(h);
	cout<<cpy->next->next->random->label<<endl;
}