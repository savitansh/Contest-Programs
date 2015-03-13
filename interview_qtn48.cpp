#include <iostream>
#include <string>
using namespace std;

string st;

int print(int k, string s){
	string t1(s);// = new string();
	string t2(s);// = new string();
	
	t2[k] = '1';
	cout<<t2<<endl;
	bool flag = false;
	for(int i=k+1; st[i]!= '\0'; i++){
		if(t1[i] == '0')
		{
			flag = true;
			k = i;
			break;
		}
	}
	if(flag == true)
	{
		print(k,t2);
		print(k,t1);
	}
	return 0;
}

int main(){
cin>>st;
int len = st.length();
int k = -1;
for(int i=0; i<len; i++){
	if(st[i] == '?')
		st[i] = '0';
}

for(int i=0; i<len; i++){
	if(st[i] == '0'){
		k = i;
		break;
	}
}
if(k == -1)
return 0;
cout<<st<<endl;
print(k,st);
}