#include<bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

PII ar[100];
int till[100];

void solve()
{
	int n,p;
	string s,t;
	sd(n);
	sd(p);
	for(int i=0;i<p;i++)
	{
        cin>>t>>s;
        ar[i].S = ((t[0]-'0')*10 + (t[1]-'0'))*60 + ((t[3]-'0')*10 + (t[4]-'0'));
        if(ar[i].S < 8*60) ar[i].S += 12*60;
        ar[i].F = ((s[0]-'0')*10 + (s[1]-'0'))*60 + ((s[3]-'0')*10 + (s[4]-'0'));
        if(ar[i].F <= 8*60) ar[i].F += 12*60;
        //cout<<ar[i].F<<" "<<ar[i].S<<endl;
	}
	sort(ar,ar+p);
	for(int i=0;i<p;i++)
	{
        swap(ar[i].F,ar[i].S);
	}

    int ans=0;
	for(int i=0;i<p;i++)
	{
        int x=-1,last=-1;
        for(int j=0;j<n;j++)
        {

            if(till[j]<=ar[i].F)
            {
                if(till[j] > last)
                {
                    x=j;
                    last = till[j];
                }
            }
        }
        if(x!=-1)
        {
            ans++;
            till[x] = ar[i].S;
        }
	}
	printf("%d\n",ans);
}

int main()
{
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
}