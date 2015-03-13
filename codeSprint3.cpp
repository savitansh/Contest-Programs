#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int calc(){
	char inp[100];
	cin>>inp;
	int data[100],temp[100];
	int i=0;
	for(i=0; inp[i] != '\0'; i++){
		data[i] = inp[i] - 'a';
	}

	int len = strlen(inp);
	i = len-1;
	while((i-1) >= 0 && data[i-1] >= data[i]){
			i--;
	}
	i--;
	bool cannot = false;
	
	if(i >= 0 && data[i] < data[i+1]){
		int j = i+1;
		while(j<len && data[j] > data[i]){
			j++;
		}
		
		j--;

		if(data[j] > data[i])
			{
				int tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;

				int l = 0;
				for(int k=i+1; k < len; k++)
					temp[l++] = data[k];

				sort(temp , temp + l);

				int n = i+1;
				for(int k=0; k<l; k++){
					data[n++] = temp[k];
				}
			}
	}	else {
		cannot = true;
	}

	if(cannot == false)
	{
		for (int i = 0; i < len; ++i)
		{
			char c = (char)(data[i] + 'a');
			cout<<c;
		}
		cout<<endl;
	}	else
	{
		cout<<"no answer"<<endl;
	}

	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T){
		calc();
		T--;
	}
	return 0;
}