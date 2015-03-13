#include<iostream>
using namespace std;

bool findIntersect(int a,int b , int c , int d){
	if(a > b){
		int t = a;
		a = b;
		b  = t;
	}
	if(c > d){
 		int t = c;
 		c = d;
 		d = t;
	}
	if((a<c && c<b && b<d) || (c<a && a<d && d<b))
		return true;
	return false;
}

int main(){
	int n;
	long int x[1001];

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i];
	}

	bool intersect = false;

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n-1 ; ++j)
		{
			if(findIntersect(x[i],x[i+1],x[j],x[j+1]))
			{
					intersect = true;
					break;
			}
		}
	}
	if(intersect == true)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}