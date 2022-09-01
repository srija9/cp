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

struct flower{
    ll h;
    ll b;
};

ll flowers(vector<flower> &a, ll n){
    vector<ll> dp(n+1);
    map<ll, ll> sortedFlowers;
    dp[1] = a[1].b;
    sortedFlowers[a[1].h] = a[1].b;
    ll ans = dp[1];

    loop(i, 2, n) {
        dp[i] = a[i].b;
        auto it = sortedFlowers.lower_bound(a[i].h+1);
        if(it != sortedFlowers.begin()){
            it--;
            dp[i] += it->second;
        }
        sortedFlowers[a[i].h] = dp[i];
        it = sortedFlowers.upper_bound(a[i].h);
        while(it != sortedFlowers.end() and it->second <= dp[i]){
            auto t = it;
            t++;
            sortedFlowers.erase(it);
            it = t;
        }
        ans = max(ans, dp[i]); 
    }

}

int main(int argc, char const *argv[])
{
init_code();

int n;
cin>>n;
vector<flower> arr(n+1);
loop(i, 1, n){
    cin>>arr[i].h;
}
loop(i, 1, n){
    cin>>arr[i].b;
}

cout<<flowers(arr, n);
 
return 0;
}