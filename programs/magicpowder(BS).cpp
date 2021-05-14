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

int Q[1000006], req[1000006],X,N;
//quantity array, required array, magic powder, no of incredents;

bool check(int mid)
{
	int magic = 0;
	for(int i=0;i<N;i++)
	{
		if(mid*req[i]<=Q[i]) continue;
		magic+= mid*req[i] - Q[i];
		//cout<<magic<<endl;
	}
	return magic <=X;
}


int main(int argc, char const *argv[])
{
	init_code();
	cin>>N>>X;
	
	for(int i=0;i<N;i++)
	{
		cin>>Q[i];
	}
	for(int i=0;i<N;i++)
	{
		cin>>req[i];
	}
	

	int low=0, high=1000000, mid = (low+high)/2;
	while(high-low>1)
	{
		if(check(mid)){
			low=mid;
		}else{
			high=mid;
		}
		mid = (low+high)/2;
	}
	if(check(high)) cout<<high<<endl;
	else cout<<low<<endl;
	
	return 0;
}

	