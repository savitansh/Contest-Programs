#include<iostream>
using namespace std;

long long int powers[80];
int generatePowers(){
	powers[0] = 1;
	for(int i=1; i<66; i++){
		powers[i] = powers[i-1] * 2;
	}
	return 0;
}

int low = 0 , high = 64;
int findLowerBound(long long int N , int low , int high){
	int mid = 0;
	while(low <= high){
		mid = (low + high)/2;
		if(powers[mid] < N && powers[mid+1] <= N)
			low = mid+1;
		else if(powers[mid] > N  && powers[mid+1] > N)
			high = mid-1;
		else if(powers[mid] < N && powers[mid+1] > N)
			break;
		else if(powers[mid] == N)
			break;
	}
	//cout<<mid<<endl;
	return mid;
}

int calc(){
	long long int N;
	cin>>N;

	int indx = 64;
	
	bool turn = false;
	while(N > 1){
	indx = findLowerBound(N , 0 , indx + 1);
	long long int closest = powers[indx];
		if(closest < N)
			N = N - closest;
		else
			N = N / 2;
			turn = !turn;
		}
	if(turn == true)
		cout<<"Louise"<<endl;
	else
		cout<<"Richard"<<endl;		
	return 0;
}

 int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	generatePowers();
	
	while(T){
		calc();
		T--;
	}
	return 0;
}