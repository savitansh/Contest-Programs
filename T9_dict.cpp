/*
implement T9 Dictionary
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> nodes[10000];
vector<int> word_list;

int digit[30];

void set_digits(){
	digit['a'] = digit['b'] = digit['c'] =  2;
	digit['d'] = digit['e'] = digit['f'] =  3;
	digit['g'] = digit['h'] = digit['i'] =  4;
	digit['j'] = digit['k'] = digit['l'] =  5;
	digit['m'] = digit['n'] = digit['o'] =  6;
	

}

int get_digit(char letter){
	return digit[letter];
}

int make_trie(){
	int size = word_list.size();
	for(int i=0; i<size; i++){
		string word = word_list[i];
		parent = 0;
		int digit = get_digit(word[i]);
		nodes[parent].push_back(digit);
		parent = digit;

		for(int i=1; word[i] != '\0'; i++){
			digit = get_digit(word[i]);
			nodes[parent].push_back(digit);
			parent = digit;
		}
	}
}

int main(){
	
}