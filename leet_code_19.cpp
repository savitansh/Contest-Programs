/*
@author savitansh
circular gas stations
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	queue<int> tmp_q;
	int visited[10000];
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int total_gas = 0, total_cost = 0,diff=0;
        int siz = gas.size();
        total_cost += cost[0];
        total_gas += gas[0];
        
        tmp_q.push(0);
        int i = 0;
        while(tmp_q.size()<siz){
        	diff = total_gas - total_cost;
        	while(diff<0 && !tmp_q.empty()){
        		int j = tmp_q.front();
        		if(visited[j]==1)
        			break;
        		else
        			visited[j] = 1;

        		tmp_q.pop();
        		total_gas -= gas[j];
        		total_cost -= cost[j];
        		diff = total_gas - total_cost;
        	}
        	i = (i + 1) % siz;
        	total_cost += cost[i];
        	total_gas += gas[i];
        	tmp_q.push(i);
        if(tmp_q.empty())
        		return -1;
        }
        if(tmp_q.size() == siz && total_gas>=total_cost)
        	return tmp_q.front();
        
        return -1;
    }
};

int main(){
	Solution s;
	vector<int> gas,cost;
	gas.push_back(6);
	gas.push_back(0);
	gas.push_back(1);
	gas.push_back(3);
	gas.push_back(2);
	cost.push_back(4);
	cost.push_back(5);
	cost.push_back(2);
	cost.push_back(5);
	cost.push_back(5);
	cout<<s.canCompleteCircuit(gas,cost)<<endl;
}