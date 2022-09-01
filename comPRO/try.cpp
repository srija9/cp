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
    int t,n;
    cin>>t;
    ll x;
    while(t--)
    {
    	cin>>n>>x;
    	ll a[n];
    	unordered_map<ll, ll> mp;
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}

    	for(int i=0;i<n;i++)
    	{
    		if(mp.find(a[i]) == mp.end())
    			mp[a[i]]=1;
    		else
    			mp[a[i]]++;
    	}

        int max=0;

        for(int i=0;i<n;i++)
        {
            if(mp[a[i]]>max)
                max=mp[a[i]];
        }

        ll count = 0,num = 1000000007,match,changes=0;
        for(int i=0;i<n;i++)
        {
            match = x ^ a[i];
            //cout<<match<<endl;
            if(mp.find(match) != mp.end() && num != a[i])
            {
                //cout<<"pass\n";
                num = a[i];
                if(count<mp[match]+mp[a[i]])
                {
                    changes = mp[a[i]];
                    count = mp[match]+mp[a[i]];
                }
                }
            
        }

        cout<< (max>count?max:count) << " "<<changes<<'\n';


    }

    return 0;
}