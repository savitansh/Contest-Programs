#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
}*head;

struct node *reverse(struct node **p, int n){
	struct node *t1 = NULL, *t2,*t3;
	t2 = *p;
	t3 = t2->next;
	for(int i=0; i<n; i++){
		t2->next = t1;
		t1 = t2;
		t2 = t3;
		t3 = t3->next;
	}
	head = t1;
	t1 = head;
	return t1;
}

int traverse(struct node *t1, int n){
for(int i=0; i<n; i++){
	cout<<t1->data<<" ";
	t1 = t1->next;
	}	
}

int mididx = 1;
struct node *find_mid(struct node *p){
struct node *p1,*p2;
	p1 = p2 = p;	
	while(1){
		if(p1->next != NULL && p1->next->next != NULL){
			p1 = p1->next->next;
			p2 = p2->next;
			mididx++;
		}else if(p1->next != NULL){
			p1 = p1->next;
			p2 = p2->next;
			mididx++;
		}else
		break;
	}
	return p2;
}

bool pallindrom_check(struct node *h1, struct node *h2){
	bool yes = true;
	while(h1!=NULL && h2!= NULL){
		if(h1->data == h2->data){
			h1 = h1->next;
			h2 = h2->next;
		}else{
			yes = false;
			break;
		}
	}
	return yes;
}

int main(){
	struct node *h;
	head = new node;
	head->data = 1;
	head->next = NULL;
	h = head;
	int n = 4;
	struct node *p = new node;
		p->data = 2;
		p->next = NULL;
		h->next = p;
		h = p;
	p = new node;
		p->data = 2;
		p->next = NULL;
		h->next = p;
		h = p;
	p = new node;
		p->data = 1;
		p->next = NULL;
		h->next = p;
		h = p;	
	// for(int i=2; i<n; i++){
	// 	struct node *p = new node;
	// 	p->data = i;
	// 	p->next = NULL;
	// 	h->next = p;
	// 	h = p;
	// }
	h = head;
	//reverse(&h,6);
	//h = head;
	// for(int i=0; i<6; i++){
	// 	cout<<h->data;
	// 	h = h->next;
	// }
	struct node *mid = find_mid(h);
	cout<<mid->data<<endl;
	struct node *h1 = NULL;
	cout<<mididx<<endl;
	if(n % 2 == 0)
		h1 = reverse(&h,mididx-1);
	else
		h1 = reverse(&h,mididx);

	struct node *h2 = mid;
	bool res = pallindrom_check(h1,h2);
	h1->next = h2;
	reverse(&h1,mididx);
	cout<<res<<endl;
return 0;	
}