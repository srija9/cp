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

//void init_code(){
//fast_io;
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
//}

int main(int argc, char const *argv[])
{
	//init_code();

	int a[7] = {3, 4, 5,6, 0, 1, 2};


	int low =0, high =6;
	int mid = (low+high)/2;
	//cout<<mid;
	while(high-low>1)
	 {
	 	if(a[0]<a[mid])
		{
			low=mid;
	 		//cout<<low;
	 	}
		else
		{
	 		high = mid;
	 	}
	 	mid= (low+high)/2;
	 }

			cout<<a[low];
			cout<<a[high];
			cout<<6-low;

	return 0;
}

