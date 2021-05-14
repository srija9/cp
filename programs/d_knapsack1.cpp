#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
#define vi             vector<ll>
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
	ll n,w;
	cin>>n>>w;
	vi val(n,0);
	vi wt(n,0);
	vi dp1(w+1, 0);
	vi dp2(w+1, 0);
	loop(i, 0, n-1){
		cin>>wt[i]>>val[i];
	}
	loop(i, 0, n-1){
		loop(j, 1, w){
			if(wt[i]>j){
				dp2[j] = dp1[j];
			}else{
				dp2[j] = max({dp2[j], dp1[j], val[i]+ dp1[j-wt[i]]});

			}
		}
		dp2.swap(dp1);
		dp2.clear();
	}
    cout<<dp1[w];

	return 0;
}

