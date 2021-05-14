#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
#define vi             vector<ll>
#define endl 		   "\n"
#define mid(l,r)	   (l+(r-1)/2)
#define loop(i,a,b)	   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) for(int i=(a);i>=(b);i--)

void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[])
{
	init_code();

	ll n,w;
	cin>>n>>w;
	vi val(n,0);
	vi wt(n,0);
	loop(i, 0, n-1)
	{
		cin>>wt[i]>>val[i];
	}

	ll dp1[n*1000+1];
	ll dp2[n*1000+1];
	loop(i, 0, n*1000)
	{
		dp1[i] = inf;
		dp2[i] = inf;
	}
    
    dp1[0] = 0;
    dp1[val[0]] = wt[0];
    loop(i, 1, n-1){
    	loop(j, 0, n*1000){
    		if(val[i]>j){
    			dp2[j] = dp1[j];
    		}else{
    			dp2[j] = min({dp2[j], dp1[j], wt[i] + dp1[j-val[i]]});
    		}
    	}
    	loop(k, 0, n*1000)
    	{
    		dp1[k] = dp2[k];
    		dp2[k] = inf;
    	}
    }
    int result = 0;
     loop(i, 0, n*1000){
     	if(dp1[i] <= w) result = i;
     }
     cout<<result;
   
	return 0;
}