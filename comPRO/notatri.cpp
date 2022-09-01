//spoj - code: NOTATRI // Binary Search 
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
    cin>>n;
    while(true)
    {
        vector<int> arr(n,0);
        loop(i,0,n-1)
        {
        	cin>>arr[i];
        }
        
        sort(arr.begin(),arr.end());
        int ans = 0;

        loop(i,0,n-1)
        {
        	for(int j=i+1;j<n-1;j++)
        	{
        		ans += arr.end() - (upper_bound(arr.begin(), arr.end(),arr[i]+arr[j]));
        	}
        }

        cout<<ans<<endl;
        cin>>n;
        if(n==0) break;
    }

    return 0;
}


//input
// 3
// 1 2 3 
// 4
// 5 2 6 9
// 0

//output
//0
//2