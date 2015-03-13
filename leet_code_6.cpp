#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	int find_lowest(vector<int> &num, int i, int size){
		int min1 = 1000000,m;
		int v = num[i];
		for(int j=i+1; j<size; j++){
			if(num[j] > v && num[j] < min1){
				min1 = num[j];
				m = j;
			}
		}
		return m;
	}

	void swap(vector<int> &num, int i, int j){
		int t = num[i];
		num[i] = num[j];
		num[j] = t;
	}

    void nextPermutation(vector<int> &num) {
        bool flag = false;
        int size = num.size();
        if(size <= 1)
        	return;
        
        for(int j=size-1; j>=1; j--){
            if(num[j-1]  < num[j]){
                int idx1 = find_lowest(num,j-1,size);
                swap(num,idx1,j-1);
                sort(num.begin() + j,num.begin() + size);
                flag = true;
                break;
            }
        }
        if(flag == false){
        	sort(num.begin(),num.begin() +size);
        }
    }
};

int main(){
	Solution s;
	vector<int> num;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int v;
		cin>>v;
		num.push_back(v);
	}
	s.nextPermutation(num);
	for(vector<int>::iterator it = num.begin(); it != num.end(); it++){
		cout<<*it<<" ";
	}
}
