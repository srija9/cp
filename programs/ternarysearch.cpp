// status : 3

#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

double f(double t, int n, vector<ll> &s, vector<ll> &d){
    double mx=0.0, mn= 1e18, val;
    for(ll i=0; i<n; i++)
    {
    	val = s[i]*t+d[i];
    	mx = max(val, mx);
    	mn = min(val, mn);
    }
    return mx-mn;
}

int ternarySearch(vector<ll> &arr, int target)
{
	int l=0, r=arr.arr.size()-1;
	while(l<=r)
	{
		int m1 = l+(r-l)/3;
		int m2 = r-(r-l)/3;
		if(arr[m1]==target) return m1;
		if(arr[m2]==target) return m2;
		if(target<arr[m1]) r=m1-1;
		else if(target > arr[m2]) l=m2+1;
		else{
			l=m1+1;
			r=m2-1;
		}

	}
	return -1
}

int main()
{

   init_code();

int n,k;
cin>>n>>k;
double l=0.0, r=(double)k, m1,m2, e=1e-7, ans;

ll s[n], d[n];
for(int i=0;i<n;i++)
{
	cin>>s[i];
	cin>>d[i];
} 


while((r-l)>e)
{
	m1 = l+(r-l)/3;
	m2 = r-(r-l)/3;
	if(f(m1)>f(m2)){
		l = m1;
	}else{
		r = m2;
	}
}

ans = f(l);


return 0;
}