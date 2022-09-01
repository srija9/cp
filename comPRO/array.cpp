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

    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;

    	int a[n],sum=0,input;
    	vector<int> min;
    	vector<int> max;
    	for(int i=0; i<n; i++)
    	{
    		cin>>input;
    		a[i] = input;
    		sum += input;
    	}

    	int value = sum/n;

    	for(int i=0; i<n; i++)
    	{
    		if(arr[i]>value)
    		{
    			max.push_back(arr[i]);
    		}
    		else if(arr[i]<value)
    		{
    			min.push_back(arr[i]);
    		}
    	}

    	for(int i=0; i<n; i++)
    	{
    		
    	}
    }

    return 0;
}