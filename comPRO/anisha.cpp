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
    int t,n;
    cin>>t;
    while(t--) {
    	cin>>n;
    	string s;
    	cin>>s;
    	int countB=0, countW=0;
    	vector<int> arr;
    	arr.push_back(0);
    	if(s[0]=='B')
    	{
    		countB++;
    	}
    	else
    	{
    		countW++;
    	}

    	for(int i=1;i<n;i++){
    		if(s[i]!=s[i-1])
    		{
    			arr.push_back(i);
    			if(s[i]=='B')
    			{
    				countB++;
    			}
    			else
    			{
    				countW++;
    			}
    		}
    	}
    	if(countW <= countB)
    	{
    		cout<<countW;
    	}
    	else
    		cout<<countB;

    	cout<<"\n";

    }


    return 0;
}