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

ll minStepsToOneTD(int n, ll *dp){
	if(n == 2 or n == 3) return 1;
	if(n==1) return 0;
	if(n < 1) return inf;
	if(dp[n] != 0) return dp[n];

	ll div_by_3 = inf, div_by_2 = inf, sub_by_1 = inf;
	if(n%3 == 0){
		div_by_3 = 1 + minStepsToOneTD(n/3, dp);
	}
	if(n%2 == 0){
		div_by_2 = 1 + minStepsToOneTD(n/2, dp);
	}
	sub_by_1 = 1 + minStepsToOneTD(n-1, dp);
	return dp[n] = min({div_by_3, div_by_2, sub_by_1});
}

ll minStepsToOneBU(int n){
	ll *dp = new ll[n+1]();
	dp[0] = inf;
	dp[1] = 0;
	dp[2] = dp[3] = 1;
	loop(i, 4, n){
		ll div_by_3 = inf, div_by_2 = inf, sub_by_1 = inf;
	if(i%3 == 0){
		div_by_3 = 1 +dp[i/3];
	}
	if(i%2 == 0){
		div_by_2 = 1 + dp[i/2];
	}
	sub_by_1 = 1 + dp[i-1];
	dp[i] = min({div_by_3, div_by_2, sub_by_1});

	}

	return dp[n];
}

int main()
{
    init_code();
    int n;
    cin>>n;
    ll *dp = new ll[n+1]();
    cout<<minStepsToOneTD(n, dp)<<endl;

    return 0;
}