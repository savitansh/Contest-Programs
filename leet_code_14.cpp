/*
@author savitansh
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int start,min_len;
	int M1[100],M2[100];
		
	Solution(){
	 start = 0;
	 min_len=1000000;	
	 }

	bool compare(){
		bool flag = true;
		for(int i=0; i<100; i++){
			if(M1[i]>M2[i]){
				flag = false;
				break;
			}
		}
		return flag;
	}
	int update(int i, int j){
		if(j-i+1<min_len){
			min_len = j-i+1;
			start = i;
			}
	}
		
    string minWindow(string S, string T) {
    	bool found = false;
    	for(int i=0;i<100; i++){
    		M1[i] = M2[i] = 0;
    	}
    	int p1=0,p2=0;
		int n = S.length();
		int n2 = T.length();
		
		for(int i=0; i<n2; i++)
			(M1[T[i]-'A'])++;

		while(p2 < n){
			if(S[p2]==' '){
				p2++;
				continue;
			}
			(M2[S[p2]-'A'])++;
			while(compare()){
				found = true;
				update(p1,p2);
				//cout<<p1<<","<<p2<<endl;
				(M2[S[p1]-'A'])--;
				p1++;
				while(M1[S[p1]-'A']==0 && p1<=p2)
					p1++;
			}
			p2++;
		}
		if(found==true){
		string ans;
		char out[1000];
		int j=0;
		for(int i=start; i<=start+min_len-1; i++)
			out[j++] = S[i];
		out[j++] = '\0';
		ans = string(out);
		return ans;
		}else
		return "";
    }
};

int main(){
	Solution s;
	string S = string("this is a test string");
	string T = string("tist");
	cout<<S<<","<<T<<endl;
    	
	cout<<s.minWindow(S,T)<<endl;
}