#include <iostream>
#include <deque>

using namespace std;

deque<int> main_deque;
deque<int> tmp_deque;

int main(){
	int n;
	cin>>n;
	char start[101][4],end[101][4];

	for(int i=0; i<n; i++){
		cin>>start[i]>>end[i];
	}
	main_deque.push_back(0);

	while(1){
		int ticket = tmp_deque.front();
		tmp_deque.pop();

	}
}