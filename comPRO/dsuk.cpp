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

struct edge {
	int u, v, w;
} edges[10000];

bool compare(const edge & e1, consr edge & e2){
	return e1.w < e2.w;
}

int p[10000];

int get_root(int u){
	if(p[u] == -1) return u;
	return p[u] = get_root(p[u]);
}

void do_union(int u, int v){
	if(rand() % 2){
		p[u] = v;
	}else{
		p[v] = u;
	}
}

int main()
{
    init_code();
    int n; 
    int m; 
    cin>>n>>m;
    for(int i=0; i<m; i++){
    	cin>>edges[i].u>>edges[i].v>>edges[i].w
    }

    //print the mst using kruskal's algorithm

    //step 1: create a forest

    for(int i=1; i<=n;++i){
    	p[i] = -1;
    }

    //step 2: sort the edges

    sort(edges, edges+m, compare);

    //step 3: iterate through the edge list

    // vector<edge> mst;
    cout<<"MST Follow\n";
    int cost_of_ST = 0;

    for(int i=0; i<m; ++i){
    	const edge & e = edges[i];
    	//this is the edge
    	int root_of_u = get_root(e.u);
    	int root_of_v = get_root(e.v);

    	if(root_of_u == root_of_v){

    	}else{
    		do_union(root_of_u, root_of_v);
    		// mst.push_back(e);
    		cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
    		cost_of_ST += e.w;

    	}
    }

    cout<<"Total cost of MST = " << cost_of_ST << "\n";



    return 0;
}