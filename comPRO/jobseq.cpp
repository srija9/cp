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

bool comp(vector<int>&e1, vector<int>&e2)
{
	return e1[1]<e2[1];
}

int main()
{
    init_code();
    vector<vector<int>>activities={{4,6},{3,7},{5,8},{7,10},{13,15},{4,10}};
    sort(activities.begin(),activities.end(),comp);

    int free=0;
    int ans=0;
    for(int i=0; i<activities.size();i++){
    	if(free<=activities[i][0])
    	{
    		free=activities[i][1];
    		ans++;
    	}
    }

    cout<<ans;


    return 0;
}