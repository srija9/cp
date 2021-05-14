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
	while(t){
		int n,uc=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]== 1 or a[i]==3){
            	uc++;
            }
		}
          cout<<uc<<endl;
          t--;
	}


	return 0;
}
