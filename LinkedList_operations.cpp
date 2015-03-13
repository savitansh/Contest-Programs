/*
@author savitansh
reverse every k elements of a Linked List
*/
#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void print_list(struct node *p){
	while(p != NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

void reverse_nodes(struct node **start, struct node **end){
	struct node *t1 = *start;
	struct node *t2,*t3;
	t2 = t1->next;
	t3 = t2->next;
	while(1){
	t2->next = t1;
	t1 = t2;
	if(t2 == *end)
		break;
	t2 = t3;
	t3 = t3->next;	
	}
	
}

void reverse_K_nodes(struct node **p, int k){
	struct node *h = *p;
	struct node *t1,*t2,*t3,*t4;
	t1 = h;
	t2 = t1;
	t4 = new node();
	bool stnode = false;

	struct node *p2;
	bool flag = false;
	while(1){

	for (int i = 0; i < k; ++i){
		if(t2->next != NULL)
		t2 = t2->next;
		else{
			flag = true;
			break;
		}	
	}
	if(t2->next != NULL)
	t3 = t2->next;
	else
		break;
	reverse_nodes(&t1, &t2);
	if(stnode == false){
		p2 = t2;
		stnode = true;
	}
	
	t1->next = t3;
	t4->next = t2;
	t4 = t1;
	t1 = t3;
	t2 = t1;
	if(flag == true)
		break;
	}	
	while(p2 != NULL){
		cout<<p2->data<<" ";
		p2 = p2->next;
	}
}

int main(){
	struct node *head = NULL,*p=NULL;
	head = new node();
	head->data = 0;
	p = head;
	for(int i=1; i<=25; i++){
		struct node *tmp = NULL;
		tmp = new node();
		tmp->data = i;
		tmp->next = NULL;
		p->next = tmp;
		p = tmp;
	}
	struct node *q = p;
	p = head;
	reverse_K_nodes(&p , 4);
	//p = head;
	//print_list(p);
	//reverse_nodes(&p , &q);
	//
}