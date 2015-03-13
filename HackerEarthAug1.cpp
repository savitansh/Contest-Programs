#include<iostream>
using namespace std;

int findBits(int val){
	int bitCount = 0;
	while(val > 0){
		if(val & 1 != 0)
		bitCount++;
		val = val >> 1;
	}
	return bitCount;
}
int main(int argc, char const *argv[])
{
	/* code */
	int N;
	long long int count[20];
	long long int triplets[20],val[100000];
	cin>>N;

	for(int i=0; i<N; i++){
		cin>>val[i];
	}

	for(int i=0; i<N; i++){
		int v = val[i];
		int c = 0;
		while(v > 0){
			int x = v % 10;
			if( x == 2) c = c | 1;
			else if( x == 3) c = c | 2;
			else if( x == 5) c = c | 4;
			else if(x == 7) c = c | 8;
			v = v / 10;
		}
		for(int i=1; i<16; i++)
			if( (i & c) == i  )	count[i]++;
		
	}

	for(int c = 1; c<16; c++){
		if(count[c] > 2){
			triplets[c] = (count[c] * (count[c] -1) * (count[c] - 2)) / 6;
	//		cout<<c<<":"<<triplets[c]<<endl;
		}
	}
	int t1 = 0;

	for(int i=1; i<16; i++){
		int bitCount = findBits(i);
		if(bitCount %2 == 0)	
			t1 = t1 - triplets[i];
		else
			t1 = t1 + triplets[i];	
	
	}

	cout<<t1<<endl;
	return 0;
}