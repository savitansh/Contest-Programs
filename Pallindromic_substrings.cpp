#include <iostream>
#include <algorithm>
using namespace std;

	
int calc(){
	string inp;
	int t = 0;
	cin>>inp;
	int n = inp.length();
	string suffix_arr[1001];

	for(int i=0; i<n; i++){
		char suffix[1000];
		int k=0;
		for(int j=i; j<n; j++){
			suffix[k++] = inp[j]; 
		}
		suffix[k] = '\0';
		suffix_arr[t++] = string(suffix);
	}
	sort(suffix_arr, suffix_arr+t);

	
	int ans = (suffix_arr[0]).length();
	for(int i=0; i<t-1; i++){
		string s1 = suffix_arr[i];
		string s2 = suffix_arr[i+1];
		int l1 = s1.length();
		int l2 = s2.length();
		int l = min(l1,l2);
		int prefix_len = 0;
		for(int i=0; i<l; i++)
		{
			if(s1[i] == s2[i])
				prefix_len++;
			else
				break;
		}
		ans = ans + l2 - prefix_len;
	}
	cout<<ans<<endl;

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