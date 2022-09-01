// greedy approach with heaps, priority queues

#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-l)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    init_code();
    ll t;
    cin>>t;

    while(t--)
    {
    	ll n,m,sum1=0,sum2=0,ans=0;
    	cin>>n>>m;
    	priority_queue<ll> mx_q;
    	priority_queue<ll, vector<ll>, greater<ll> > mn_q;
    	for(ll i=0; i<n; i++)
    	{
    		ll x;
    		cin>>x;
    		sum1+=x;
    		mn_q.push(x);
    	}
    	for(ll i=0; i<m; i++)
    	{
    		ll x;
    		cin>>x;
    		sum2+=x;
    		mx_q.push(x);
    	}
    	while(sum1<=sum2)
    	{
    		int min_el = mn_q.top();
    		int max_el = mx_q.top();

    		if(min_el >= max_el) break;

    		ans++;

    		sum1 -= min_el;
    		sum1 += max_el;
    		sum2 -= max_el;
    		sum2 += min_el;

    		mn_q.pop();
    		mx_q.pop();
    		mn_q.push(max_el);
    		mx_q.push(min_el);

    	}
    	if(sum2>=sum1) cout<<-1;
    	else cout<<ans;

    	cout<<"\n";

    }

    return 0;
}