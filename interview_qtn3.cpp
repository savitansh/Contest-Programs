/*
@author savitansh
find merging point of 2 lists
2. swap alternating nodes
3. all nodes at odd places come at start and all even nodes appended 
in reverse order to list of odd nodes
*/
#include <iostream>
using namespace std;


struct node{
	int data;
	struct node *next;
};

struct node *t1,*t2,*t3;
	
struct node *create(int n){
	int val;
	cin>>val;
	struct node *head;
	head = new node();
	head->data = val;
	head->next = NULL;
	struct node *p,*t;
	t = head;
	for(int i=1; i<n; i++){
		int val;
		cin>>val;
		p = new node();
		p->next = NULL;
		p->data = val;
		t->next = p;
		t = p;
	}
	return head;
}

struct node *find_merge(struct node *h1, struct node *h2){
	t1 = h1;
	t2 = h2;
	cout<<t1->data<<","<<t2->data<<endl;
	int l1 = 0, l2 = 0;
	while(t1!=NULL){
		l1++;
		t1 = t1->next;
	}
	while(t2!=NULL){
		l2++;
		t2 = t2->next;
	}
	cout<<l1<<","<<l2<<endl;
	int diff = 0;
	if(l1>l2){
		diff = l1-l2;
		t1 = h1;
		t2 = h2;
	}else if(l1 < l2){
		diff = l2 - l1;
		t1 = h2;
		t2 = h1;
	}
	while(diff>0){
		t1 = t1->next;
		diff--;
	}

	while(t1 != NULL && t2 !=NULL){
		if(t1 == t2)
			return t1;
		t1 = t1->next;
		t2 = t2->next;
	}
	return NULL;
}

int merge(struct node *h1, struct node *h2){
	struct node *t1,*t2;
	t2 = h2;
	t1 = h1;
	while(t2->next != NULL){
		t2 = t2->next;
		t1 = t1->next;
	}
	t2->next = t1;	
}

int print_list(struct node *h){
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

struct node *find_intersection(struct node *h1, struct node *h2){
	struct node *h3 = NULL,*p=NULL,*tmp;
	h3 = new node();
	p = h3;
	while(h1 != NULL && h2!= NULL){	
		if(h1->data == h2->data){
			tmp = new node();
			tmp->data = h1->data;
			tmp->next = NULL;
			p->next = tmp;
			p = tmp;
			h1 = h1->next;
		}
		if(h1->data < h2->data)
			h1 = h1->next;
		else if(h1->data > h2->data)
			h2 = h2->next;
	}
	if(h3->next != NULL)
		return h3->next;
	return NULL;
}


struct node *make_sum(struct node *root){
	struct node *tmp = root, *prev=NULL;
	int s = 0;
	while(tmp != NULL){
		s = s + tmp->data;
		if(tmp->next->data == 0)
			break;
		tmp = tmp->next;
	}
	tmp->data = s;
	root = tmp;
	prev = root->next;
	tmp = tmp->next->next;

	while(1){
		if(tmp == NULL || tmp->next==NULL)
			break;
		int s = 0;
	while(tmp != NULL ){
		s = s+(tmp->data);
		if(tmp->next->data == 0)
			break;
		tmp = tmp->next;
	}
	tmp->data = s;
	prev->next = tmp;
	prev = tmp->next;
	tmp = tmp->next->next;	
	}

	return root;
}

node *swap_nodes(node *h){
	node *t0,*t1,*t2,*t3,*old;
	t0 = NULL;
	t1 = h;
	old = h->next;
	t2 = h->next;
	t3 = h->next->next;
//	cout<<t1->data<<","<<t2->data<<","<<t3->data<<endl;	
	
	while(1){
	t2->next = t1;
	t1->next=t3;
	if(t0 != NULL)
		t0->next=t2;
	t0 = t1;
	if(t3 != NULL){
	t2 = t3->next;
	t1 = t3;
	t3 = t3->next->next;	
		}else
		break;
	
//	cout<<t0->data<<","<<t1->data<<","<<t2->data<<","<<t3->data<<endl;	
	}
	h = old;
	return h;
}


node *change_order(node *h){
	node *tail = h,*old = h,*t,*old2;
	int counter = 0;
	old2 = h;
	while(tail->next != NULL){
		tail = tail->next;
		counter++;
	}
	int i=0;
	while(i<counter/2){
		t = h->next;
		h->next = h->next->next;
		tail->next = t;
		t->next = NULL;
		tail = t;
		h = h->next;
		i++;
	//	cout<<t->data<<" ";
	}
	cout<<h->data<<endl;
	if(counter % 2!=0){
		t = h->next;
		cout<<t->data<<endl;
		h->next = h->next->next;
		tail->next = t;
		t->next = NULL;
	}
	old = h->next->next;
	//h = old;
	node *t1 = h->next, *t2 = h->next->next,*t3 = h->next->next->next;
	t1->next = NULL;
	while(t2!=NULL){
		t2->next = t1;
		t1 = t2;
		t2 =t3;
		if(t3 != NULL)
		t3 = t3->next;
	}
	
	h->next = t1;
		h = old2;
	return h;
}

int main(){
	struct node *h1,*h2;
	h1 = create(10);
	//h2 = create(4);

//	merge(h1,h2);
	//print_list(h2);
	//cout<<h2->data;
	// struct node *merge_point;

	// merge_point = find_merge(h1,h2);
	// cout<<"merged:"<<merge_point->data;

	//struct node *intersect_head = find_intersection(h1,h2);
	//print_list(intersect_head);
	//struct node *h3 = make_sum(h1);
	//print_list(h3);
//	node *h4 = swap_nodes(h1);
	cout<<"ok";
	node *h4 = change_order(h1);
	print_list(h4);
}