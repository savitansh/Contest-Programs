/*
author @Savitansh
problem Hackerrank september 101 prob Jim and the Skyscrapers
*/
#include <iostream>
#include <stack>
#include <map>
using namespace std;

stack<int> stk;
int tower_count[1000001];

long long int total_ways = 0;
int add_to_ways(long long int v)
{
    if(v > 1)
        total_ways = total_ways + (v*(v-1))/2;
    return 0;
}

int arr[1000000];
    
int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
    cin>>arr[i];
    }

    stk.push(arr[0]);
    tower_count[arr[0]] = 1;

    for (int i = 1; i < n; ++i){
        
        if(arr[i] < stk.top()){

            stk.push(arr[i]);
            tower_count[ arr[i] ] = tower_count[ arr[i] ] + 1;
            
        }  else if(arr[i] > stk.top()) {

            while(!stk.empty() && arr[i] > stk.top()) {
              
                int val = stk.top();
                if(tower_count[val] > 0){
                    add_to_ways(tower_count[val]);
                    tower_count[val] = 0;
                }
               stk.pop();
            }
            tower_count[arr[i]] += 1;
            stk.push(arr[i]);
        } else if(arr[i] == stk.top()){

            (tower_count[ arr[i] ]) += 1;
            stk.push(arr[i]);    
        }        	
    }

    while(!stk.empty()){

        int val = stk.top();
        if(tower_count[val] > 0){
        add_to_ways(tower_count[val]);
        tower_count[val] = 0;
        }
        stk.pop();
    }
    cout<<total_ways * 2<<endl;
    return 0;
}
