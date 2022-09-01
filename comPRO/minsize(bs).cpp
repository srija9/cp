//https://leetcode.com/problems/minimum-size-subarray-sum/
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
    int n;
    ll target;
    int num[n];

    for(int i=0; i<n; i++)
    {
    	cin>>num[i];
    }

    for(int i=1; i<n; i++)
    {
    	num[i] = num[i] + num[i-1];
    }

    

    return 0;
}