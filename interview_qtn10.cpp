/*
 There is a linked list whose node is defined as follows

	struct node
	{
		int x,y;
		node* next;
	};
We had to implement a function which takes the head of linked list,
and if any three consecutive points lie on same horizontal or vertical line,
we had to remove the middle node. The linked list will either be empty 
or will contain atleast two nodes. The function prototype was:

	void remove(node* head)
	{

	} 
*/
#include <iostream>
using namespace std;

struct node{
	int x,y;
	node* next;
};

void remove(node *head){
	node *t1,*t2,*t3;
	t1 = head;
	t2 = head->next;
	t3 = head->next->next;
	while(t3!=NULL){
		while((t1->x == t2->x  && t2->x == t3->x) || (t1->y == t2->y  && t2->y == t3->y)){
			t1->next = t3;
			t2 = t3;
			t3 = t3->next;
			if(t3 == NULL)
				break;
		}
		t1 = t1->next;
		t2 = t2->next;
		t3 = t3->next;
	}
}

struct node *create(int n){
	int val1,val2;
	cin>>val1>>val2;
	struct node *head;
	head = new node();
	head->x = val1;
	head->y = val2;
	head->next = NULL;
	struct node *p,*t;
	t = head;
	for(int i=1; i<n; i++){
		int val1,val2;
		cin>>val1>>val2;
		p = new node();
		p->next = NULL;
		p->x = val1;
		p->y = val2;
		t->next = p;
		t = p;
	}
	return head;
}

int main(){
	struct node *head = create(8);
	remove(head);
	struct node *t = head;
	while(t!=NULL){
		cout<<t->x<<","<<t->y<<endl;
		t = t->next;
	}
}