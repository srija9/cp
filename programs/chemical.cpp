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

void reg(int *arr,int i, int n, vector<int> &v, int s)
{
    if(i==n+1)
    {
    	v.push_back(s);
    	return;
    }
    
   // cout<<arr[i]+s<<" "<<s<<"\n";
	reg(arr,i+1,n,v,arr[i]+s);
	reg(arr,i+1,n,v,s);

}


int main(int argc, char const *argv[])
{
	init_code();
	int ra,rb,n;
	cin>>ra;
	cin>>rb;
	cin>>n;
	int a[n],b[n],c[n];
	vector<int> a1;
	vector<int> b1;
	vector<int> c1;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}

	
	reg(a,1,n,a1,0);
	reg(b,1,n,b1,0);
	reg(c,1,n,c1,0);
	// for (int i=0; i<a1.size(); i++)
 //       cout << a1[i] << " ";
 //   cout<<"\n";
	// for (int i=0; i<b1.size(); i++)
 //       cout << b1[i] << " ";
 //   cout<<"\n";
 //    for (int i=0; i<c1.size(); i++)
 //       cout << c1[i] << " ";
 //   cout<<"\n";

    int max = 10000;
   for(int i=0;i<c1.size()-1;i++)
   {
       if(a1[i]/ra == b1[i]/rb and a1[i]%ra == 0 and b1[i]%rb == 0)
       { 
       	if(max>c1[i])
       	{
       		max = c1[i];
       	}
       	
       }

   }

   if(max == 10000)
   {
   	max = -1;
   }

  cout<<max;  
	return 0;
}
