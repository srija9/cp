////binary search // minimization in binary search...

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

//n books,Pi pages, k students
//1<=N<=10^5
//1<=M<=NULL
//1<Pi<=10^9
// F F F F F T T T T FINDING first T (minimization).

bool isValid(ll books[], ll n,ll k,ll ans)
{
	int students=1;
	ll current_pages = 0;

	for(int i =0; i<n;i++)
	{
		if(current_pages+books[i]>ans){
			current_pages = books[i];
			students++;
			if(students>k)
			{
				return false;
			}
		}
		else{
			current_pages+=books[i];
		}
	}
	return true;
}
 
ll binarySearchBooks(ll books[],ll n,ll k)
{
	ll total_pages =0;
	ll s=0,e=0;
	for(int i=0;i<n;i++)
	{
         total_pages += books[i];
         s = max(s,books[i]);
	}
	e = total_pages;
	int finalAns = s;

	while(s<=e)
	{
		ll mid = (s+e)/2;

		if(isValid(books,n,k,mid)){
			finalAns = mid;
			e = mid - 1;
		}
		else{
			s=mid+1;
		}
	}
	return finalAns;
}


int main(int argc, char const *argv[])
{
	init_code();
	ll n,k;
	cin>>n>>k;
	ll books[100005];
	for(int i=0;i<n;i++)
	{
		cin>>books[i];
	}
	
	cout<<binarySearchBooks(books,n,k)<<endl;

	return 0;
}

//INPUT:
// 4 2
// 10 20 30 40
//OUTPUT:
//60
