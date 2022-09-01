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

int p[1000];

int get_root(int u){
	if(p[u]==-1) return u;
	return p[u] = get_root(p[u]);
}

void merge(int u, int v) {
	if(rand() % 2 ) p[u] = v;
	else p[v] = u;
}

int main()
{
    init_code();
    int n;
    int m;
    cin>>n>>m;

    //vector<pair<int, int> > edgeList;
    set<pair<int, int>> edges;

    for(int i=0; i<m; ++i){
    	int u, v;
    	cin>>u>>v;
    //	edgeList.push_back(make_pair(u,v));
    	edges.insert(make_pair(min(u,v), max(u,v)));
    }

    set<pair<int, int> > dup_edges = edges;

    int Q;
    cin>>Q;

    vector<pair<int, int>> queries;

    for(int i=0;i<Q;++i){ 
    	int u,v;
    	cin>>u>>v;

    	//if there is an edge between u and v then remove it.
    	//And after the removal, u need to tell the no 
    	// of connected components in the resulted graph

    	pair<int, int> p = make_pair(min(u,v), max(u,v));
    	queries.push_back(p);
    	dup_edges.remove(p);
    }

    int conn_comps = n;
    // this is because all the nodes are initially disconnected

    for(int i=1; i<=n; ++i){
    	p[i] = -1;
    }

    //need to add the edges which are still not removed
    for(pair<int, int> e: dup_edges) {
    	int root_of_u = get_root(e.first);
    	int root_of_v = get_root(e.second);
    	if(root_of_v != root_of_u) {
    		merge(root_of_u, root_of_v);
    		conn_comps -= 1;
    	}
    }

    vector<int> ans(Q);

    for(int i=Q-1; i>=0; --i){
    	ans[i] = conn_comps;
    	if(edges.find(queries[i]) != edges.end()) {
    		//if that edge existed in the first place
    		int root_of_u = get_root(queries[i].first);
    	    int root_of_v = get_root(queries[i].second);
    	    if(root_of_v != root_of_u) {
    		   merge(root_of_u, root_of_v);
    		   conn_comps -= 1;
    	    }
    	}
    }

    for(int i=0; i<Q; ++i){
    	cout<<"num of CC after the removal of i_th edge is "<<ans[i]<<"\n";
    }

    return 0;
}