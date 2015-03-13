#include <iostream>
using namespace std;

int vec[30];
int vec2[30];
string inp;
	
int set_freq_table(int i, int j){
	for(int s=i; s<=j; s++)
		vec[(inp[s]-'a')] += 1;
	
}

int reset_freq_table(){
	for(char c='a'; c<='z'; c++)
		vec[c-'a'] = 0;
}

int check_freq(int p1, int p2){
	for(char c='a'; c<='z'; c++)
		vec2[c-'a'] = 0;

	for(int s=p1; s<=p2; s++)
		vec2[inp[s]-'a']++;

	bool flag = true;
	for(char c='a'; c<='z'; c++)
		if(vec[c-'a']!=vec2[c-'a']){
			flag = false;
			break;
		}
	if(flag == true)
	return 1;
	return 0;	
}

int calc(){
	cin>>inp;
	int n = inp.length();
	
	int count = 0;
	for(int i=0; i<n; i++){
		for(int len=0; i+len<n; len++){
		reset_freq_table();
		set_freq_table(i,i+len);

		for(int j=i+1; j+len<n; j++){
			if(check_freq(j,j+len)==1)
				count++;
		}
		}
	}
	cout<<count<<endl;
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