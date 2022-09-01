#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod            1000000007
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

int main()
{
    init_code();

    int d[100][100] = {mod};
    for(int i =0; i < edges_count; i++){
    	int u, v, c;
    	d[u][v] = c;
    } 

    // floyd-warshall algorithm
    for(int k=1;k<=n;k++) { // new allowed intermediatary node
    	for(int u = 1; u <= n; u++){
    		for(int v = 1; v <= n; v++){
    			d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
    		}
    	}
    }

    for(int u = 1; u <= n; u++){
    	for(int v = 1; v <= n; v++){
    		cout << "distance("<<u<<","<<v<<") = " << d[u][v] <<"\n";
    	}
    }

    return 0;
}