#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> lst;
vector<long long>::iterator it,it2;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long radius,x1,x2,y1,y2;
    int n,m;
    cin>>n;

    for(int i=0; i<n; i++){
    cin>>radius;
    lst.push_back(radius*radius);
    }

    sort(lst.begin(),lst.end());

    int ans = 0;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x1>>y1>>x2>>y2;

    long long d1 = x1*x1 + y1*y1;
    long long d2 = x2*x2 + y2*y2;

    long long dis = min(d1,d2);
    long long dis2 = max(d1,d2);

    it = lower_bound(lst.begin(),lst.end(),dis);
    it2 = lower_bound(lst.begin(),lst.end(),dis2);
    if(it2 == lst.end())
        it2--;

    while(it2 != lst.begin() && (*it2) > dis2)
    it2--;    

    int count = max(it2-it+1,0l);
    //cout<<count<<*it<<","<<*it2<<endl;
    ans += count;
    }
    cout<<ans<<endl;
    return 0;
}
