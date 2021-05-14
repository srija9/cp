#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
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

void solve()
{
	int n,q;
	cin>>n>>q;

	int i,j,k,l;

	vector<int> a(n);
	vector<int> fre(32,0);

	auto editt=[&](int x, int ext){
		int i10;

		int base=1;

		for(i=0;i<32;i++)
		{
			if(x&base)
				fre[i] += ext;

			base *= 2;
		}
	};

	for(i=0;i<n;i++)
	{
		cin>>a[i];
		editt(a[i],1);
	}

	auto cal = [&](){
		int i;
		int ans = 0;

		int base=1;

		for(i=0;i<32;i++)
		{
			if(fre[i])
				ans+=base;

			base *=2;
		}
		return ans;
	};

	cout<<cal()<<endl;

	while(q--)
	{
		int idx,val;
		cin>>idx>>val;

		idx--;
		editt(val,1);
		editt(a[idx],-1);

		a[idx] = val;

		cot<<cal()<<endl;
	}
}




int main(int argc, char const *argv[])
{
	init_code();
	int t = 1;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}
