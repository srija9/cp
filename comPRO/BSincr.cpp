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
 
int binarysearch(int *arr, int n, int target)
{
    int lo = 0, hi=n-1;
    while(lo<=hi){
        int m = mid(lo, hi);
        if(arr[m]==target){
            return m;
        }
        else if(arr[m]>target)
        {
              hi = m-1;
        }else {
            lo = m+1;
        }
   }
   return -1;
}

int binarysearchOnSortedRotated(int *arr, int n, int target)
{
   int lo = 0, hi=n-1;
   while(lo<=hi)
   {
       int m = mid(lo,hi);
       //cout<<m<<endl;
       if(arr[m] == target) return m;
       else if(arr[m]>=arr[lo])
       {
           //case 1
           if(target >= arr[lo] and target<=arr[m])
           {
               hi = m-1;
           } else {
               lo = m+1;
           }
       }else{
           //case 2
           if(target>=arr[m] and target<=arr[hi])
           {
               lo = m+1;
           } else{
               hi = m-1;
           }
       }
   }
   return -1;
}

int squareRoot(int n)
{
	int lo = 1, hi=n-1;
	int ans = -1;
	while(lo<=hi)
	{
		int m = mid(lo,hi);
		if(m*m ==n) return m;
		else if(m*m>n)
		{
			hi=m-1;
		}
		else{
			ans = m;
			lo = m+1;
		}
	}
	return ans;
}

int main()
{

init_code();
 int n;
 cin>>n;
 // int a[n];
 // loop(i,0,n-1)
 // {
 // 	cin>>a[i];
 // }
 // int target;
 // cin>>target;
 // int res = binarysearchOnSortedRotated(arr,n,target);
 // cout<<res<<endl;

int root = squareRoot(n);
cout<<root;
return 0;
}

//input
//9
//23 45 67 2 3 4 5 8 10
//67