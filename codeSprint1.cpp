#include <iostream>
#define MIN  1000000000
using namespace std;

int calc(){
	long long int x1=0,y1=0,x2=0,y2=0,x=0,y=0;
	cin>>x>>y>>x1>>y1>>x2>>y2;

	long long int d1 = y2-y;
	long long int d2 = y-y1;
	long long int d3 = x-x1;
	long long int d4 = x2-x;

	long long int mindist = MIN;
	mindist = min(d1,mindist);
	mindist = min(d2,mindist);
	mindist = min(d3,mindist);
	mindist = min(d4,mindist);
	cout<<mindist<<endl;

return 0;
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