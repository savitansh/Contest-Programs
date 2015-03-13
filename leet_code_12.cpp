#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(head == NULL)
		return NULL;

		ListNode *p1=head,*p2=head,*p3=head;
		bool found = false,entered = false;
		while(1){
			if(p1 == p2 && entered == true){
				found = true;
				break;
			}
			if(p1->next != NULL)
				p1 = p1->next;
			else
				break;

			if(p2->next != NULL){
				if(p2->next->next == NULL)
					break;
				p2 = p2->next->next;
			}else
			break;
			entered = true;
		}
		//cout<<entered<<endl;
		if(found == false)
			return NULL;
		else{

			p1 = p2;
			p1 = p1->next;
			int loop_size = 1;
			while(p1 != p2){
				p1 = p1->next;
				loop_size++;
			}
			cout<<loop_size<<endl;
			p1 = head;
			p2 = head;
			for(int i=0; i<loop_size; i++){
				p2 = p2->next;
			}
			while(p1 != p2){
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
    }
};

int main(){
	ListNode *head,*n1,*n2,*n3,*n4;
	head = new ListNode(1);
	n1 = new ListNode(2);
	n2 = new ListNode(3);
	n3 = new ListNode(4);
	n4 = new ListNode(5);
	head = NULL;//n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	Solution c;
	ListNode *p = c.detectCycle(head);
	if(p != NULL)
	cout<<p->val<<endl;
}