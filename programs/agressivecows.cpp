//binary search // maximization in binary search...

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

int main(int argc, char const *argv[])
{
	//init_code();
	int n,c;
	cin>>n>>c;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int low=0,high=a[n-1], mid, best=0;
	while(low<=high)
	{
		mid = (low+high+1)/2;
		int cnt=1,left=0;
		for(int i=1;i<n && cnt<c;i++)
		{
			if(a[i]-a[left]>=mid)
				left = i, cnt++;
		}
		if(cnt >= c)
		{
			best = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	cout<<best<<endl;
	return 0;
}
