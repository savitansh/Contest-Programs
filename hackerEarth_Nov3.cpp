#include <iostream>
using namespace std;

int main(){
	int idx = 1;
	while(idx<=30){
		idx+=(idx&(-idx));
		cout<<idx<<endl;
	}
}