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

#define X first
#define Y second

vector<pair<int, int> > graph[100100];
int dijkstra_parent[10000];

const INF = 100000;

int main()
{
    init_code();

    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
    	int u,v,w;
    	cin>> u >> v >> w;
    	graph[u].push_back(make_pair(v,w));
    	//graph[v].push_back(make_pair(u,w)); for undirected 

    }

    vector<int> is_selected(n+1, 0);

    // is_selected[i] = 1 means if that node belongs to the set S described
    // in the algorithm

    vector<int> dist(n+1, INF);

    // we run dijkstra

    int src;
    cin>>src;

    dist[src] = 0;

    for (int i=1; i <= n; i++) {
    	// the algo works in n steps

    	// 1. Find the node in T which has smallest tentative distance

    	int tent_d = INF, next_node = -1;
    	for (int u = 1; u <= n; u++) if(!is_selected[u]) {
    		if(dist[u] < tent_d)
    		{
    			tent_d = dist[u];
    			next_node = u;
    		}
    	}

    	// 2. remove it from T and add to S
    	is_selected[next_node] = 1;

    	// 3. Relax the edges going out of it
    	for(pair<int, int> e: graph[next_node]) if(!is_selected[e.X]) {
    		int new_dist = dist[next_node] + e.Y;
    		if(new_dist < dist[e.X]) {
    			dist[e.X] = new_dist; 

    			dijkstra_parent[e.X] = next_node;
    		}
    	}

    }

    return 0;
}