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

ll loothouseTD(vector<ll> &arr, vector<ll> &dp, int i)
{
	if(i == 0){
		return dp[0] = arr[0];
	}
	if(i == 1){
		return dp[1] = max(arr[0], arr[1]);
	}
	if(dp[i] != -1) return dp[i];

	return dp[i] = max(loothouseTD(arr, dp, i-1), loothouseTD(arr, dp, i-2)+arr[i]);

}

ll loothouseBU(int n, vector<ll> &arr){
	vector<ll> dp(n, 0);
	dp[0] = arr[0];
	dp[1] = arr[1];
	for(int i=2; i<n; i++){
		dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
	}
	return dp[n-1];
}

int main()
{
    init_code();
    int n;
    cin>>n;
    vector<ll> arr(n,0);

    loop(i,0,n-1){
    	cin>>arr[i];
    }

    vector<ll> dp(n, -1);

    cout<<loothouseTD(arr, dp, n-1);

    return 0;
}