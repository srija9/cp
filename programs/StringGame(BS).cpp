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

int a[1000006], n, k;
//200000
string s, t;

bool check(int mid)
{
	string temp = s;
	for(int i=1; i<=mid; i++)
	{
		temp[a[i]-1] = '$';
	}
	int j=0;
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i]==t[j]) j++;
		if(j==t.size()) return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	init_code();
	cin>>s;
	cin>>t;
	for(int i=1;i<=s.size();i++)
	{
		cin>>a[i];
	}

	int low=0, high=s.size(), mid = (low+high)/2;
	while(high-low>1)
	{
		if(check(mid)){
			low=mid;
		}else{
			high=mid;
		}
		mid = (low+high)/2;
	}
	if(check(high)) cout<<high<<endl;
	else cout<<low<<endl;
	
	return 0;
}
