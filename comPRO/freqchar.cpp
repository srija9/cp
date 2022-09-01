//hash map:
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

    unordered_map<char, int> mp;
    string str = "aaaabbbcccccbccc";
    for(int i=0;i<str.size();i++){
         mp[str[i]]++;
    }

    char max = 'a';

    // for(int i=0;i<mp.size();i++){
    //      if(mp[i]>mp[max])
    //      {
    //      	max = i
    //      }
    // }

    for(auto x: mp){
    	if(mp[x.first]>mp[max])
    	{
    		max = x.first;
    	}
    }

    cout<<max<<endl;

    return 0;
}