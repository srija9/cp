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
	int n,m;
	cin>>n>>m;
	vector<vector<char> >grid(n+1, vector<char>(m+1));
	loop(i,1,n){
		string str;
		cin>>str;
		loop(j, 1, m){
			grid[i][j] = str[j-1];
		}
	}
	vector<vector<int> > dp(n+1, vector<int>(m+1,0));
	dp[n][m] = 1;
	looprev(i,n,1){
		looprev(j,m,1){
			if(i==n and j==m) continue;
			if(grid[i][j] == '#'){
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = ((i==n)?0:dp[i+1][j]) + ((j==m)?0:dp[i][j+1]);
		}
	}
	cout<<dp[1][1];


	return 0;
}

// 7 5
// ....#
// .....
// .##..
// ....#
// #.#..
// ..##.
// ..#..

//5 ans
