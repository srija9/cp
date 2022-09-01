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

void permutation(string &s, int n){
    
}

int main(int argc, char const *argv[])
{
    init_code();

    int n;
    string s;
    cin>>n;
    cin>>s;

    ll ans = 0;
    for(int g = n-1; g >= 0; g--){
        ans = (ans%mod + dp[2][g]%mod)%mod;
    }
    cout<<ans;
    
    return 0;
}