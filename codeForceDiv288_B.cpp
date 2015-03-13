#include <iostream>
using namespace std;

	string s;
	int inp[1000000];

int swap(int inp[], int i, int j){
	int t = inp[i];
	inp[i] = inp[j];
	inp[j] = t;
	return 0;
}

int main(){
	cin>>s;
	int i=0;
	for(i=0; s[i] != '\0'; i++)
		inp[i] = s[i] - '0';

	int to_swap = i-1;

	for(int k=i-1; k>=0; k--){	
		if(inp[i-1] > inp[k] && inp[k]%2==0){
			to_swap = k; 
		}
	}	

	if(to_swap != i-1)
		swap(inp,i-1,to_swap);
	else{
		for(int k=i-1; k>=0; k--){	
		if(inp[k]%2==0){
			to_swap = k; 
			break;
		}
	}
	if(to_swap != i-1)
		swap(inp,i-1,to_swap);
	else{
		cout<<-1<<endl;
		return 0;
		}

	}
	for(int l=0; l<i; l++)
			cout<<inp[l];
		cout<<endl;
		
	return 0;

}