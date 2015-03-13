#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int> > out_times;

bool sorter(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
  return firstElem.first < secondElem.first;
  if(firstElem.first == secondElem.first)
  return firstElem.second < secondElem.second;
}

int main(){
    int n, duration = 0;
    int in_time[1001];
    cin>>n;
    for(int i=0; i<n; i++){
    cin>>in_time[i];
    cin>>duration;
    pair<int,int> out_time = make_pair((in_time[i] + duration) , i+1);
    out_times.push_back(out_time);
    }


    sort(out_times.begin(), out_times.end(), sorter);

    for(int i=0; i<n; i++){
    cout<<out_times[i].second<<" ";
    }

cout<<endl;
return 0;
}
