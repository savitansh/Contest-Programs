#include <iostream>
using namespace std;

int main(){
int n,m,i,j,a,b;
cin>>n>>m>>j>>i>>a>>b;

int v[4];
v[0] = (m-i);
v[1]= (n-j) ;
v[2] = (i-1);
v[3] = (j-1);

if(v[0]%a == 0 && v[1]%b == 0 && (((v[0]/a)%2 ==0 && (v[1]/b)%2 == 0) || ((v[0]/a)%2 ==1 && (v[1]/b)%2 == 1))){
	ans = min(ans,max(v[0]/a , v[1]/b))<<endl;
}else if(v[0]%a==0 && v[3]%b==0 && (((v[0]/a)%2 ==0 && (v[3]/b)%2 == 0) || ((v[0]/a)%2 ==1 && (v[3]/b)%2 == 1))){
	cout<<min(v[0]/a, v[3]/b)<<endl;
}else if(v[2]%a==0 && v[1]%b==0 && (((v[2]/a)%2 ==0 && (v[1]/b)%2 == 0) || ((v[2]/a)%2 ==1 && (v[1]/b)%2 == 1))){
	cout<<v[2]/a<<endl;
}else if(v[2]%a==0 && v[3]%b==0 && (((v[2]/a)%2 ==0 && (v[3]/b)%2 == 0) || ((v[2]/a)%2 ==1 && (v[3]/b)%2 == 1))){
	cout<<v[2]/a<<endl;
}else
	cout<<"Poor Inna and pony!"<<endl;

return 0;
}