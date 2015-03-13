/*
generate all anagrams of a string
*/
#include <iostream>
using namespace std;

int fun(int n){
	int l = queue.size();
	for(int k=0; k<l; k++)
	str1 = queue.pop();
	tmp = str1;
	tmp = tmp + inp[n];
	queue.push_back(tmp);
	for(int i=0; i<=n-1; i++){
		str1 = tmp;
		swap(str1[i],str1[n]);
		queue.push_back(str1);
	}
	fun(n+1);
}
int main(){
	
}