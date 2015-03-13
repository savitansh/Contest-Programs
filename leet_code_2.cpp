#include <iostream>
#include <set>
using namespace std;

int M[1000][1000];

bool check(string s,int i, int j, set<string> &dict){
	if(M[i][j] == 1)
		return true;
	else if(M[i][j] == -1)
		return false;
	char q[1000];
	int t=0;
	for(int k=i; k<=j; k++)
	{
		q[t++] = s[k];
	}	
	q[t] = '\0';
	string word = string(q);

	if(dict.find(word) != dict.end()){
		M[i][j] = 1;
	}else{
		M[i][j] = -1;
	}

	if(M[i][j] == 1)
		return true;
	else
		return false;
}

bool print_string(string s, int i, int j){
	for(int k=i; k<=j; k++)
		cout<<s[k];
	cout<<" ";
}

bool wordBreak(string s, set<string> &dict, int start,int end) {
    for(int i=start; i<=end; i++){
    	for(int j=i+1; j<=end; j++){
    		if(check(s,i,j,dict)){
    			if(wordBreak(s,dict,i,j))
    				print_string(s,i,j);
    		}
    	}
    }  
}

int main(){
	set<string> dict;// = {"flikart","online","shopping"};
	dict.insert("flikart");
	dict.insert("online");
	dict.insert("shopping");
	string s ="flikartonlineshopping";
	int n = s.length(); 
	wordBreak(s,dict,0,n-1);
}