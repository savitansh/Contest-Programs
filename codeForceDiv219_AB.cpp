#include <iostream>
using namespace std;

int len(long long int m){
	int l = 0;
	while(m>0){
		m = m/10;
		l++;
	}
	return l;
}
long long int count[21];
int main(){
	long long int w,m,k,t=1,total=0;

	cin>>w>>m>>k;
	int l = len(m);
	
	for(int i=0; i<l; i++)
		t= t*10;

	for(int i=1; i<=20; i++){
		count[i] = t - m;
		m = t;
		t = t*10;
	}
	for(int i=1; i<=20; i++){
		if(w/(k*l) >= count[i]){
			total += count[i];
			w = w-(k*l * count[i]);
			l++;
			//cout<<total<<" "<<w<<endl; 
		}else{
			total += (w/(k*l));
			break;
		}
	}

	cout<<total<<endl;
}