#include <iostream>
using namespace std;

int main(){
	for(int i=0; x[i] !='\0'; i++){
		flag = false;
		for(int j=t; z[j] != '\0'; j++){
			if(z[j] == x[i])
			{
				t = j;
				flag = true;
				break;
			}
		}
		if(flag == false)
			break;
	}

	for(int i=0; y[i] !='\0'; i++){
		flag2 = false;
		for(int j=t; z[j] != '\0'; j++){
			if(z[j] == y[i])
			{
				t = j;
				flag2 = true;
				break;
			}
		}
		if(flag2 == false)
			break;
	}

	if(flag == true && flag2 == true && l1 == (l2+l3))
		cout<<"YES";
	else
		cout<<"NO";
}