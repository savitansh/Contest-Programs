/*
@author savitansh
*/
#include <iostream>

using namespace std;

int calc(){
	char str1[100000];
	cin>>str1;

	char toFind = str1[0];
	bool found = true;

	int toDel = 0;
	for (int i = 1; str1[i] != '\0'; ++i)
	{
		if(toFind == 'B' && found == true){
				toFind = 'A';
				found = false;
		}		
		else if(found == true){
			toFind = 'B';
			found = false;
		}

		if(str1[i] == toFind)
		{
			found = true;
		}	else 
			toDel++;
	}
	cout<<toDel<<endl;

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