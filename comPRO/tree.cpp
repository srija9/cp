//tree using vector of vectors.

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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pdfs;

 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

 //     1
 //    /  \
 //   2    6
 //  / \  / 
 // 3   4 7 
 //    /
 //    5   

vector<vector <int> > adj;
int n;//num of nodes.

vector<int> level, subtree_size;

void dfs(int cur=1,int par=-1)
{
	//  cout<<cur<<'\n';          // dfs order
	//level[cur] = level[par]+1;  // levels calculation

	subtree_size[cur] = 1;

	for(int neighb : adj[cur])
	{
		//neighb can be parent or it can be child
		if(neighb == par)
			continue;

		dfs(neighb,cur);
		subtree_size[cur] += subtree_size[neighb]; //calculating subtree size of node.
	}
}

int main()
{
    init_code();

    cin>>n;
    adj.resize(n+1);
    level.resize(n+1);
    subtree_size.resize(n+1);

    for(int i=0;i<n-1;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    level[0]=-1;
    dfs();

    for(int i=1;i<=n;i++)
    	cout<<i<<' '<<level[i]<<'\n';

    return 0;
}

// input:
// 7
// 1 2
// 2 3
// 2 4
// 4 5
// 1 6
// 6 7

// output:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
