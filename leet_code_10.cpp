/*
merge k sorted linked lists
*/
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
	ListNode *nodes[100000];

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		int size = lists.size();
		for(int i=0; i<size; i++){
			nodes[j++] = lists[i];
		}
		for(int k=0; k<j; k++){
			if((nodes[k])->val < min_val){
				min_val = (nodes[k])->val;
				min_node = nodes[k];
				min_k = k;
			}
		}
		next_node = final_node->next;
		final_node->next = min_node;
		min_next_node = min_node->next;
		min_node->next = next_node;
		nodes[min_k] =min_next_node; 	        
    }
};

