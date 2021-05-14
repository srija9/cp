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
	init_code();
	int a[1000006], N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}

	int low =0, high = N-1, mid = (low+high)/2;
	while(low<high)
	{
		if(a[0]<a[mid])
		{
			low = mid;
			cout<<low;
		}
		else{
			high=mid;
		}
		mid = (low+high)/2;
	}

	cout<<a[low];
	
	return 0;
}
