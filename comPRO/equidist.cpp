#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-l)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void mazepath(int i, int j, int m, int n, string osf){
    if(i==m-1 && j==n-1)
    {
        cout<<osf<<"\n";
        return;
    }
    if(i>=m || j>=n){
        return;
    }

    mazepath(i, j+1, m, n, osf+"R");
    mazepath(i+1, j, m, n, osf+"D");
    mazepath(i+1, j+1, m, n, osf+"->");

}

void cellpath(int i, int n, string osf){
    if(i==n-1)
    {
        cout<<osf<<"\n";
        return;
    }
    if(i>=n)
        return;
    for(int j=1; j<=6; j++)
    {
        cellpath(i+j, n, osf+to_string(j)+"->");
    }
}

void lexicoOrder(int n, int i){
    if(n<i)
    {
        return;
    }
    cout<<i<<endl;
    for(int j= (i==0)?1:0; j<=9; j++)
        lexicoOrder(n, 10*i+j);

}

int main()
{
    init_code();
    // mazepath(0, 0, 3, 3, "");
    cellpath(0, 7, "");
    

    return 0;
}