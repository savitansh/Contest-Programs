/**
 * Definition for an interval.
 * Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 */
 #include <iostream>
 #include <vector>
 using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval>::iterator it;
      vector<Interval> final_set;
      bool flag = false;
      Interval curr;
      for(it = intervals.begin(); it != intervals.end(); it++){
      	curr = *it;
      	flag = true;
            if(curr.end < newInterval.start){
      		final_set.push_back(curr);
      		if((it+1) != intervals.end() && (*(it+1)).start >= newInterval.start){
      		    break;						
      		}
      	}else
            break;
      }

      if(flag == false){
            final_set.push_back(newInterval);
            return final_set;
      }

      while(it != intervals.end() && (*it).end <= newInterval.end)
            it++;
      
      if(curr.end >= newInterval.start)
            newInterval.start = min(newInterval.start, curr.start);

      if(it != intervals.end() && (*it).start <= newInterval.end && newInterval.start <= (*it).start)
            {
                  newInterval.end = max(newInterval.end, (*it).end);
                  it++;
            }
      final_set.push_back(newInterval);

      while(it != intervals.end()){
      	final_set.push_back(*it);
      	it++;
      }
      
      return final_set;
    }
};

int main(){
      int n;
      cin>>n;
	Solution s;
	int start1,end1;
	vector<Interval> intervals;
	for(int i=0; i<n; i++){
		cin>>start1>>end1;
		Interval interval;
		interval.start = start1;
		interval.end = end1;
		intervals.push_back(interval);
	}
	Interval newInterval;
	cin>>start1>>end1;
	newInterval.start = start1;
	newInterval.end = end1;
	
	vector<Interval> merged_interval = s.insert(intervals, newInterval);
	
	for(vector<Interval>::iterator it=merged_interval.begin(); it != merged_interval.end(); it++){
		Interval intr = *it;
		cout<<intr.start<<","<<intr.end<<endl;
	}
}