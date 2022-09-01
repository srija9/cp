#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

ll dp[3005][3005];
ll arr[3005];
ll deque_(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = arr[i];
    return dp[i][j] = max(arr[i]-deque_(i+1, j), arr[j]-deque_(i, j-1));
}
 
int main(int argc, char const *argv[])
{
init_code();
memset(dp, -1, sizeof(dp));
int n;
cin>>n;
loop(i, 0, n-1){
    cin>>arr[i];
}
cout<<deque_(0,n-1);
 
return 0;
}