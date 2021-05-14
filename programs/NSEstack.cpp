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
	
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }

    int rb[n] ={0};
     stack<int> s1;
     s1.push(n-1);
     rb[n-1] = n;

     for(int i=n-2;i>=0;i--)
     {
     	while(s1.size()>0 && a[i]<a[s1.top()])
     	{
     		s1.pop();
     	}

     	if(s1.size()==0)
     	{
     		rb[i] = n;
     	}else
     	{
     		rb[i] = s1.top();
     	}
     	s1.push(i);
     }


    int lb[n] = {0};
     
     stack<int> s2;
     s2.push(0);
     lb[0] = -1;

     for(int i=1;i<n;i++)
     {
     	while(s2.size()>0 && a[i]<a[s2.top()])
     	{
     		s2.pop();
     	}

     	if(s2.size()==0)
     	{
     		lb[i] = -1;
     	}else
     	{
     		lb[i] = s2.top();
     	}
     	s2.push(i);
     }

     

     loop(i,0,n-1)
     {
     	cout<<rb[i]<<" "<<lb[i]<<"\n";
     }
    int maxArea = 0;
    loop(i,0,n-1)
    {
    	int width = rb[i] - lb[i] -1;
    	int area = a[i]*width;
    	if(area>maxArea){
    		maxArea = area;
    	}
    }

    cout<<maxArea;
	return 0;
}
