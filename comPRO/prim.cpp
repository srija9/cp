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

vector <pair<int, int> > adjList[10000]; // adj[u] = {v, w}

bool visited[10001];

set<pair<int, pair<int, int> >> edgeSet; // weight u v

int do_prims(int u){
	int weight_of_mst = 0;
	visited[u] = true;
	edgeSet.clear(); 
	for(const pair<int, int> & e: adjList[u]){
		edgeSet.insert(make_pair(e.second, make_pair(u, e.first)));
	}
	while(!edgeSet.empty()){
		auto it = *edgeSet.begin();
		edgeSet.erase(edgeSet.begin());
		pair<int, int> e = it.second;
		if(visited[e.first] && visited[e.second]) continue;
		//print
		cout<<"Edge "<< e.first<<" - "<<e.second<<" included\n";
		weight_of_mst += it.first;
		int v = visited[e.first] ? e.second : e.first;
		// v is the new node that has been added to the tree
		visited[v] = true;
		for(const pair<int, int> & e: adjList[v]){
		edgeSet.insert(make_pair(e.second, make_pair(v, e.first)));
	    }

	}

	return weight_of_mst;

}

int main()
{
    //init_code();
    int n;
    int m;
    cin>>n>>m;
    for(int i=0; i<m; ++i){
    	int u,v,w;
		cin>>u>>v>>w;
    	adjList[u].push_back(make_pair(v, w));
    	adjList[v].push_back(make_pair(u, w));
    }

    int mst = 0;
    for(int i=1; i<=n; i++){
    	if(!visited[i]){
    		mst += do_prims(i);
    	}
    }

	cout<<mst;

    return 0;
}