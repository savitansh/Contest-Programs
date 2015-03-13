#include <iostream>
using namespace std;

char ingriedeint[101];
	
int main(){
	int b1=0,b2=0,b3=0,p1,p2,p3;
	long long int money = 0;
	int stock1=0,stock2=0,stock3=0;
	long long int burger_count = 0;

	cin>>ingriedeint;
	for (int i = 0; ingriedeint[i] != '\0'; ++i){
		if(ingriedeint[i] == 'B')
			b1++;
		else if(ingriedeint[i] == 'S')
			b2++;
		else if(ingriedeint[i] == 'C')
			b3++;
	}
	cin>>stock1>>stock2>>stock3;
	cin>>p1>>p2>>p3;
	cin>>money;
	
	// while(1){
	// 	if(stock1>b1 && stock2>b2 && stock3>b3)
	// 	{
	// 		stock1 = stock1 - b1;
	// 		stock2 = stock2 - b2;
	// 		stock3 = stock3 - b3;
	// 		burger_count++;
	// 	}else
	// 	break;
	// }
//	cout<<b1<<b2<<b3<<endl;
	while(1){
		if(stock1 < b1 ){
			money = money - (b1-stock1)*p1;
			stock1 = b1;
		}
		if(stock2 < b2 ){
			money = money - (b2-stock2)*p2;
			stock2 = b2;
		}
		if(stock3 < b3 ){
			money = money - (b3-stock3)*p3;
			stock3 = b3;
		}
		if(money<0)
			break;

		while(stock1>=b1 && stock2>=b2 && stock3>=b3)
		{
			stock1 = stock1 - b1;
			stock2 = stock2 - b2;
			stock3 = stock3 - b3;
			burger_count++;
		//	cout<<burger_count<<endl;
		}
		if((stock1 ==0||b1==0) && (stock2 ==0||b2==0) && (stock3 == 0||b3==0))
			break;
		
//	cout<<burger_count<<endl;
	
	}
	long long int n2=0;
	if(money > 0)
	 n2 = money / (b1*p1 + b2*p2 + b3*p3);
	if(n2 > 0)
		burger_count = burger_count + n2;

	cout<<burger_count<<endl;
}