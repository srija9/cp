#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"


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
	int T;
    cin>>T;

    for(int i=0;i<T;++i)
    {   
    	int N,K;
    	cin>>N>>K;
    	int in1,in2;
    	vector<ll> a;
        vector<int> b;
    	for(int j=0;j<N;++j)
    	{
    		cin>>in1>>in2;
    		a.push_back(in1);
            b.push_back(in2);

      	}

      	int sum=0;
      	ll res=0;
         int ii=0;
        
      	for(int m=0;m<N;m++)
      	{ 
      		sum = sum + b[m];
      		if(sum<=K)
      		{
      			res=res+a[m];
                ii++;
      		}
      	}

      	int minPos =0;
      	for(int n=0;n<ii;n++)
      	{
      		if(a[n]<a[minPos])
      			minPos=n;
      	}
      	
      	res=res-a[minPos];
      	cout<<res<<endl;
    }
	return 0;
}