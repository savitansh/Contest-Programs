#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> vec;
vector<char>::iterator it1,it2;

int compare(string s1, string s2){
	int m = min(s1.size(),s2.size());
	int i=0;
	while(i<m && s1[i] == s2[i])
		i++;
	if(i<m && s1[i] != s2[i])
		return i;
return -1;
}

int main(){
	int n;
	string str[100];
	bool flag = true;

	cin>>n;
	for(char c='a'; c<='z'; c++)
		vec.push_back(c);

	for(int i=0; i<n; i++)
		cin>>str[i];

	for(int i=0; i<n-1; i++){
		int idx = compare(str[i],str[i+1]);
		
		if(idx < 0 && str[i].size() > str[i+1].size())
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		else if(idx >=0){
			char c1 = str[i][idx];
			char c2 = str[i+1][idx];
			it1 = find(vec.begin(),vec.end(),c1);
			it2 = find(vec.begin(),vec.end(),c2);
			int pos1 = it1 - vec.begin();
			int pos2 = it2 - vec.begin();
			if(pos1 > pos2){
			//	cout<<pos2<<","<<pos1<<endl;
				vec.erase(vec.begin()+pos2);
				it1 = find(vec.begin(),vec.end(),c1);
				vec.insert(it1+1,c2);
			}
		}
	}

	for(int i=0; i<n-1; i++){
		int idx = compare(str[i],str[i+1]);
		if(idx >= 0){
			char c1 = str[i][idx];
			char c2 = str[i+1][idx];
			it1 = find(vec.begin(),vec.end(),c1);
			it2 = find(vec.begin(),vec.end(),c2);
			int pos1 = it1 - vec.begin();
			int pos2 = it2 - vec.begin();
			if(pos1 > pos2){
				flag = false;
				break;
			}
		}
	}

	if(flag == false)
		cout<<"Impossible"<<endl;
	else{
		int sz = vec.size();
		for(int i=0; i<sz; i++)
			cout<<vec[i];
		cout<<endl;
	}
	return 0;
}