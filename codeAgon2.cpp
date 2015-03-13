#include <iostream>
#include <algorithm>
#include <vector>
#define MIN -1000000
using namespace std;

struct timings{
	int start,end;
}ppts;

vector<struct timings> ppts_v;

int to_int(string inp){

	int val = ((inp[0]-'0') * 10 + (inp[1]-'0'))*60 + (inp[3]-'0')*10 + (inp[4]-'0');
	return val;
}

bool end_sorter(const struct timings &a, const struct timings &b){
	if(a.end < b.end)
		return 1;
	return 0;
}

int main(){
	int N,p,count=0,prev=0;
	cin>>N>>p;
	for(int i=0; i<p; i++){
		string beg,end1;
		cin>>beg>>end1;
		int timing = to_int(beg);
		if(timing < 480)
			timing = timing + 720;

		ppts.start = timing;
			
		timing = to_int(end1);
		if(timing <= 480)
			timing = timing + 720;
		
		ppts.end = timing; 
		ppts_v.push_back(ppts);
	}

	sort(ppts_v.begin(),ppts_v.end(),end_sorter);
	/*for(int i=0; i<p; i++){
		cout<<ppts_v[i].start<<","<<ppts_v[i].end<<endl;
	}*/
	vector<struct timings>::iterator it;
	
	int busy[100];

	for(int i=0; i<N; i++)
		busy[i] = -1;

	for(it=ppts_v.begin(); it!=ppts_v.end(); it++){
		int max1 = -1000000,m=-1;

		for(int n=0; n<N; n++){
			if(busy[n]<=(*it).start){
				m = n;
				break;
			}

		}
		if(m>-1){
			count++;
			busy[m] = (*it).end;
		}
		
	}	
	
	cout<<count<<endl;
}