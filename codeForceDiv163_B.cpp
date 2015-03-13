#include <iostream>
using namespace std;

int main(){
	int n,t;
	char queue[60];
	cin>>n>>t;
	cin>>queue;
	
	for(int i=0; i<t; i++){
		for(int j=0; j<n-1; j++){
			if(queue[j] == 'B' && queue[j+1] == 'G'){
				char tmp = queue[j];
				queue[j] = queue[j+1];
				queue[j+1] = tmp;
				j++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<queue[i];
	}
	cout<<endl;
}