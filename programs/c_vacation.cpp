#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
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
    ll n;
    cin>>n;
    vector<vector<ll> > dp(3, vector<ll> (n, 0));
    ll a, b, c;
    cin>>a>>b>>c;
    dp[0][0] = a;
    dp[1][0] = b;
    dp[2][0] = c;
    loop(i,1,n-1){
    	cin>>a>>b>>c;
    	dp[0][i] = a + max(dp[1][i-1], dp[2][i-1]);
    	dp[1][i] = b + max(dp[0][i-1], dp[2][i-1]);
    	dp[2][i] = c + max(dp[1][i-1], dp[0][i-1]);
    }

    cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});

	return 0;
}
