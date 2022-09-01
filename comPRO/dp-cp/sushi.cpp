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

double dp[302][302][302];
double sushi(ll x, ll y, ll z, int n){
    if(x < 0 or y < 0 or z < 0) return 0;
    if(x == 0 and y == 0 and z == 0) return 0;
    if(dp[x][y][z] > -0.9) {
        return dp[x][y][z];
    }
    double exp = n + x*sushi(x-1,y,z,n) + y*sushi(x+1,y-1,z,n) + z*sushi(x,y+1, z-1,n);
    return dp[x][y][z] = exp/(x+y+z);
}
 
int main(int argc, char const *argv[])
{
init_code();

int n;
cin>>n;
memset(dp, -1, sizeof(dp));
ll one = 0, two = 0, three = 0;
loop(i, 0 , n-1){
    ll x;
    cin>>x;
    if(x==1) one++;
    else if(x==2) two++;
    else three++;
}
cout<<fixed<<setprecision(10)<<sushi(one, two, three, n);
 
return 0;
}