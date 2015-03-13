#include <iostream>
using namespace std;

int L[1001][1001];

int numDistinct(string S, string T) {
    int i=0,j=0;
   
    for(i=1; S[i] != '\0'; i++){
        for(j=1; T[j] != '\0'; j++){
            if(S[i] == T[j])
            L[i][j] = L[i-1][j-1] + L[i-1][j];
            else
            L[i][j] = L[i-1][j];
        }
    }

return L[i-1][j-1];
}

int main(){
    char S[1000];
    char T[1000];
    cin>>S;
    cin>>T;
    numDistinct(S,T);
}
