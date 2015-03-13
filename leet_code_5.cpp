/*
implement lru cache
*/
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class LRUCache{
public:
	int size;
	struct cache{
		int key,val;
		cache *next,*prev;
	}*head=NULL,*tail=NULL;
	int current_size;
	map<int ,cache* > reference;
	
	cache* get_node(int key){
        map<int ,cache* >::iterator it;
        it = reference.find(key);
        if(it != reference.end())
			return reference[key];
        else
            return NULL;
	}

	

    LRUCache(int capacity) {
        size = capacity;
        current_size = 0;
    }
    
    int get(int key) {
        cache *node;
        node = get_node(key);
        if(node != NULL){
             if(!(node == head && node == tail)){
            if(node == head){
                head = head->next;
                head->prev = NULL;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }else if(node != tail){
                node->next->prev = node->prev;
                node->prev->next = node->next;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        
        	return (node->val);
        }else
        return -1;
    }
    
    void set(int key, int value) {
     cache *node;

     node = get_node(key);
    
     if(node != NULL){
           node->val = value; 
      
        if(!(node == head && node == tail)){
            if(node == head){
                head = head->next;
                head->prev = NULL;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }else if(node != tail){
                node->next->prev = node->prev;
                node->prev->next = node->next;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        
     }  else if(current_size < size){
     	node = new cache();
     	node->key = key;
     	node->val = value;
     	reference[key] = node;
     	current_size++;
     	
     	if(head == NULL)
     		head = node;
     	
     	if(tail == NULL)
     		tail = node;
     	else
     	{
     		tail->next = node;
     		node->prev = tail;
     		tail = node;
     	}
     } else{
     	node = new cache();
     	node->key = key;
     	node->val = value;
        reference[key] = node;
        int old = head->key;
        reference[old] = NULL;
        if(head->next != NULL)
     	  head = head->next;
     	head->prev = NULL;
        if(node != tail){
     	tail->next = node;
     	node->prev = tail;
     	tail = node;
        }
     }
    }
};

int main(){
	LRUCache c(2);// = new LRUCache(4);
	c.set(2,1);
    c.set(1,1);
    cout<<c.get(2)<<endl;
	c.set(4,1);
	cout<<c.get(1)<<endl;
    cout<<c.get(2)<<endl;
    
   }