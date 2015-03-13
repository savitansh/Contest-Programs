#include <iostream>
using namespace std;

int max_no[101],min_no[101];
	
int main(){

	int m=0,s=0,s2=0;
	bool flag = true,possible = false;
	cin>>m>>s;
	if(m == 1 && s==0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	s2 = 1;
		min_no[0] = 1;
	int k = m-1;
		if(s2 < s && s>0){
			possible = true;
		while(s2 < s){
			if(min_no[k] < 9){
				min_no[k]++;
				s2++;
			}else
				k--;
			if(k < 0 && s2<s){
				flag = false;
				break;
			}	
		}
		}
			
	if(flag == false || s == 0)
			cout<<-1;
		else{
			for (int i = 0; i <m; i++)
			{
				cout<<min_no[i];
			}
		}
		cout<<" ";

		s2=0;
		possible = false;
		flag = true;
//---------------------------------------------------------------------------------			
	for (int i = 0; i < m; ++i)
	{
		max_no[i] = 9;
		s2 += 9;
	}
	k = 0;
		if(s2 >= s && s>0){
			possible = true;
		while(s2 > s){
			if(max_no[k] > 0){
				max_no[k]--;
				s2--;
			}else
				k++;
			if(k >= m && s2>s){
				flag = false;
				break;
			}	
		}
	
		}
		
		if(flag == false || possible == false)
			cout<<-1;
		else{
			for (int i = m-1; i >=0; i--)
			{
				cout<<max_no[i];
			}
		}
			
		cout<<endl;	
	
}