#include <iostream>
#include <string>
using namespace std;

string vect[300];
char decimals[100000];
string val;

int main(){
	char arr[10000];
	cin>>arr;
	int t=0,indx=0;
vect[0] = "2";
vect[1] = "2";
vect[2] = "2";
vect[3] = "3";
vect[4] = "3";
vect[5] = "3";
vect[6] = "4";
vect[7] = "4";
vect[8] = "4";
vect[9] = "5";
vect[10] = "5";
vect[11] = "5";
vect[12] = "6";
vect[13] = "66";
vect[14] = "666";
vect[15] = "7";
vect[16] = "77";
vect[17] = "777";
vect[18] = "7777";
vect[19] = "8";
vect[20] = "88";
vect[21] = "888";
vect[22] = "8888";
vect[23] = "9";
vect[24] = "99";
vect[25] = "999";
vect[26] = "9999";
	for(int i=0; arr[i] != '\0'; i++){
		if(arr[i] >= 'a')
		indx = arr[i] - 'a';
		else if(arr[i] != '0')
		indx = arr[i] - 'A';
		else if(arr[i] == '0')
			val = "0";

		val = vect[indx];
		for(int k=0; val[k] != '\0'; k++){
			decimals[t++] = val[k];
		//	cout<<val[k];
		}
	}
	decimals[t] = '\0';
	long long int total = 0;

	for(int m=0; decimals[m] != '\0'; m++){
		//cout<<decimals[m];
		total = total*10 + (decimals[m]-'0'); 
		cout<<total<<endl;
	}
	//cout<<total<<endl;
}