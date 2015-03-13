#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

	float E[100][100];

int calc(){
	float m1 =0;
	for(int w = 1; w<=5; w++){
		for(int b = 1; b<=5; b++){
			float v1 = w + 0.0;
			float v2 = b + 0.0;
			m1 = max((v1/(v1+v2) * (E[w-1][b]+1)) + v2/(v2+v1)*(E[w][b-1]-1),0.0f);
			m1 = max(m1,0.0f);
			if(m1 > 0){
			E[w][b] = m1;
			}
					
		}
	}
	
	return 0;
}
int main(){
	for(int i=0; i<10; i++){
		E[i][0] = i;
	}
	calc();
	cout<<E[5][1]<<endl;
	cout<<E[0][5]<<endl;
	cout<<E[5][0]<<endl;
	
}