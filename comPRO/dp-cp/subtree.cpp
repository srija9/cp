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

vector<ll> tree[100005];
ll dpf[100005], dpg[100005];

void g(int src, vector<bool> &vis, int m, ll parent_ans){
    vis[src] = true;
    dpg[src] = (dpf[src] * (1 + parent_ans))%mod;
    vector<ll> prefix, suffix;
    for(auto child: tree[src]){
        if(not vis[child]) {
            prefix.push_back(1+dpf[child]);
            suffix.push_back(1+dpf[child]);
        }
    }
    for(int i = suffix.size()-2; i >= 0; i--){
        suffix[i] = (suffix[i] * suffix[i+1])%m;
    }
    for(int i = 1; i < prefix.size(); i++){
        prefix[i] = (prefix[i] * prefix[i-1])%m;
    }
    int childnumber = 0;
    for(auto child : tree[src]) {
        if(not vis[child]){
        ll ways = (1 + parent_ans);
        ways = (childnumber > 0) ? (ways*prefix[childnumber-1])%m : ways;
        ways = (childnumber < suffix.size()-1) ? (ways*suffix[childnumber+1])%m : ways;
        g(child, vis, m, ways);
        childnumber++; 
        }
    }
}

void f(int src, vector<bool> &vis, int m){ // m is given modulo
    vis[src] = true;
    dpf[src] = 1; // multiply kare ke liye
    for(auto child : tree[src]){
        if(not vis[child]){
            f(child, vis, m); 
            dpf[src] = (dpf[src] * (1 + dpf[child]))%m;
        }
    }
}
 
int main(int argc, char const *argv[])
{
    init_code();
    int n, m;
    cin>>n>>m;
    loop(i, 0, n-2){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    //dfs to cal f(n)
    vector<bool> visf(n+1, false);
    f(1, visf, m);
    vector<bool> visg(n+1, false);
    g(1, visg, m, 0);

    loop(i, 1, n){
        cout<<dpg[i]<<"\n";
    }
    return 0;
}