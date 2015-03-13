#include <iostream>
#include <algorithm>
using namespace std;

struct data{
	int lv;
	int det;
	int idx;
}data[20];

bool compare(const struct data &a, const struct data &b){
	return (a.det * a.idx) > (b.det * b.idx);
}

int main(){
	int n;
	long long total=0;
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>data[i].lv;
		data[i].idx = i;
	}

	for (int i = 0; i < n; ++i){
		cin>>data[i].det;
	}

	sort(data, data+n, compare);

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<data[i].lv<<":"<<data[i].det<<endl;
	// }

	for(int i=0; i<n; i++){
		total = total + data[i].lv;
	}

	for (int i = 1; i < n; ++i)
	{
		for(int j=i; j<n; j++){
			data[j].lv = data[j].lv - (data[j].det)*(data[j].idx);
		}

		for (int j = 0; j < n; ++j){
			total = total + data[j].lv;
		}
		
	}
	cout<<total<<endl;
}