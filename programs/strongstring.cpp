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


void recur(char a[],int p,int K)
{
	int i;
	int k=K;
	if(k==1)
		{
			cout<<"YES";
			return;
		}
    if(a[p]==a[p+1])
    {
    	k--;
    	p++;
    	return recur(a,p,k);
    }
    else
    {
    	cout<<"NO";
    	return
    }
	
}

int main()
{
	init_code();
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int N,K;
		cin>>N,K;
		string arr;
		cin>>arr;
		
		for(int i=0;i<N;i++)
		{  
			recur(arr,i,K);
		}
	}
	return 0;
}