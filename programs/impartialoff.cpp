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
	
	int t;
	cin>>t;
	int n;
	while(t){
       cin>>n;
       int arr[n];
       vector<int> v;
       loop(i,1,n){
       	cin>>arr[i];
       }
       // loop(i,1,n){
       // 	cout<<arr[i]<<" ";
       // }
       sort(arr+1, arr + n+1);
       
       // loop(i,1,n){
       // 	cout<<arr[i]<<" ";
       // }
       loop(i,1,n){
       	int flag=0;
       	for(int j=1;j<i-1;j++){
       		if(arr[i]==arr[j])
       		{
       			dp[j]+=1;
       			flag = 1;
       			break;
       		}
       	}
       	if(flag==0)

       	{
       		dp[i]=1;
       	}
       }
       int sum=0, j=1;
       loop(i,1,n)
       {
        if(dp[i]!=0)
        {
        sum+=dp[i]*j;	
        j+=1;
        }
       	
       
       }
      cout<<sum<<"\n";
      t--;
	}

	
	return 0;
}
