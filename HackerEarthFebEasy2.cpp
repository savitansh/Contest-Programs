#include <iostream>
using namespace std;

int L[5001][5001];

int vowel(char c){
	if(!(c == 'a'|| c== 'e' || c=='i' || c=='o' || c=='u'))
		return 0;
	return 1;
}

string X,Y;

int lcs(int m, int n){
	for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1] && !vowel(X[i-1]))
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}

int main(){

	for(int i=0; i<5001; i++){
		for(int j=0; j<5001; j++){
			L[i][j] = -1;
		}
	}

cin>>X>>Y;
int m = X.length();
int n = Y.length();
cout<<lcs(m,n)<<endl;
return 0;
}