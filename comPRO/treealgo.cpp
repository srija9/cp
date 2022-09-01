//ENOC PROB LCA BINARY FITTING
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

const int N= 1e5 + 5, LOGN = 22; //2^20 = 1e6

vector<int> adj[N];
int h[N], p[N][LOGN] A[N];
int val[N][LOGN]; // val[u][i] = XOR of the path from node u to its (2^i -1)_th parent.

pair<int, int> lca(int u, int v){ //returns lca, xor of the path from u to v

	if(h[u] < h[v]) swap(u, v);
	// for sure h[u] >= h[v]
	//step 1 - kill the diff
	int diff = h[u] - h[v];
	int ans =0;
	//whenever you make a jump using p[][] array, update the ans also.
	for(int i=0; i<LOGN; i++) {
		if((diff & (1 << i)) != 0){ // if diff has i_th bit on then
			// diff AND (2^i) != 0, it is non-zero 
			u = p[u][i];
			ans = ans ^ val[u][i];
		}
	}

	// ans uptil here does not include the last value
	if(u == v) return {u, ans ^ A[u]};

	for(int i = LOGN - 1; i >= 0; i--){
		if(p[u][i] != p[v][i]){
			ans =ans ^ val[u][i] ^ val[v][i];
			u = p[u][i];
			v = p[v][i];
		}
	}

	//Conjecture = we will be 1 step away from the lca
	// LCA has not been included in ans till now. 

	int lca_node = p[u][0];
	return {lca_node, ans ^ val[u][0] ^ val[v][0] ^ A[lca_node]};
}

int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	// for sure h[u] >= h[v]
	//step 1 - kill the diff
	int diff = h[u] - h[v];
	for(int i=0; i<LOGN; i++) {
		if((diff & (1 << i)) != 0){ // if diff has i_th bit on then
			// diff AND (2^i) != 0, it is non-zero 
			u = p[u][i];
		}
	}

	if(u == v) return u;

	for(int i = LOGN - 1; i >= 0; i--){
		if(p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}
	}

	return p[u][0];
}

void dfs(int u , int prv) {
	h[u] = h[prv]+1;

	p[u][0] = prv;
	val[u][0] = A[u];
	//val[u][0] = A[u];
	// for(int i=1; i < LOGN; i++ ){
	// 	p[u][i] = p[p[u][i-1]][i-1];
	// }


	for(auto v: adj[u]){
		if(v == prv) continue;
		dfs(v, u);
	}

}

void solve(){
	for(int i=0;i<N;i++){
		adj[i].clear();
	}
	int n,q,u,v;
	cin>>n>>q;   //q queries
	for(int i=1; i<=n; i++) cin>>A[i];
	for(int i=1; i <= n; i++ )
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);

    for(int i=0; i<LOGN; i++){
    	p[0][i] = 0;
    	val[0][i] = 0; //identify function for XOR
    	// val[0][i] = INT_MIN; // identify function for MAX
    }

	for(int i = 1; i < LOGN; i++) {
		for(u = 1; u <= n; u++) {
			p[u][i] = p[p[u][i-1]][i-1];
			val[u][i] = val[u][i-1] ^ val[p[u][i-1]][i-1]; //u can also use max here
			// XOR the first half of the path with the second half of the path.
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		pair<int, int> x = lca(u,v);
		cout<<x.second<<endl;
		// int x = lca(u,v);
		// cout<<x<<endl;
	}
}

int main()
{
    init_code();
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}