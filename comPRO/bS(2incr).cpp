#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
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

int main(int argc, char const *argv[])
{
init_code();
 int n;
 cin>>n;
 int a[n];
 loop(i,0,n-1){
     cin>>a[i];
 }
 int target;
 cin>>target;
 int res = binarysearch(a,n,target);
 cout<<res;
return 0;
}