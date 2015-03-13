#include <iostream>
#include <map>
#define MOD 1000000000
using namespace std;
long long int ceil(long long int n, int fact){
	if(n%fact==0)
		return n/fact;
	return (n/fact)+1;
}

 long long int power(long long int x,long long int n){
	
   if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else if (n % 2 == 0) {
       long long int t = power(x, n / 2) % MOD;
        return (t * t) % MOD;
    } else {
        long long int t = power(x, (n-1) / 2) % MOD;
        return (( t * t )% MOD  * x) % MOD;
    }
}

std::map<long long, long long > m;

long long getR(long long int n){
	if(m[n] > 0)
		return m[n];

	return (getR(ceil(n,5)) * getR(ceil(n,10))) % MOD;
}

int main(){
m[0]=1;
m[1]=1;
m[2]=1;
m[3]=3;
m[4]=3;
m[5]=15;
m[6]=15;
m[7]=105;
m[8]=105;
m[9]=105;
m[10]=105;
	int T;
	cin>>T;
	while(T){
	long long n;
	cin>>n;
	long long p = power(2,ceil(n,4));
	long long rn = 0;
	if(n > 10)
	rn = p*getR(n) % MOD;
	else
	rn = m[n];
	long long x1 = (3*rn) % MOD;
	long long x2 = (4*rn) % MOD;
	long long x3 = (2*rn) % MOD;
	long long y = (5*rn) % MOD;
	long long p1 = power(x1,x2);
	long long p2 = power(x1,y);
	long long p3 = power(x2,y);
	long long p4 = power(y,x2);
	long long p5 = power(y,x1);
	long long p6 = power(x2,x1);
	long long p7 = power(x3,x1);
	long long p8 = power(x1,x3);
	long long p9 = power(x2,x3);
	long long p12 = power(x3,x2);
	long long p10 = power(x3,y);
	long long p11 = power(y,x3);
	long long p13 = power(x1,rn);
	long long p14 = power(x2,rn);
	long long p15 = power(x3,rn);
	
	long long max1 = max(p2,p3);
	max1 = max(max1,p1);
	max1 = max(max1,p4);
	max1 = max(max1,p5);
	max1 = max(max1,p6);
	max1 = max(max1,p7);
	max1 = max(max1,p8);
	max1 = max(max1,p9);
	max1 = max(max1,p10);
	max1 = max(max1,p11);
	max1 = max(max1,p12);
	max1 = max(max1,p13);
	max1 = max(max1,p14);
	max1 = max(max1,p15);
	
	cout<<max1<<endl;
	

	T--;
	}
}