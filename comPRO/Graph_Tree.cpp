// bfs algo
// flattern tree property of the tree

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

const int N = 1e5 + 5;

vector<int> adj[N];
bool vis[N];
int d[N];
int a,b,c;

int get_id(int x, int y, int z){
	return (x*((b+1)*(c+1)) + y*(c+1) + z);
}

pair<int, int> t(int r, int s, int cap){
	//transfer r litres from one jug to another jug having
	// s litres already inside it which has capacity = cap

	int remaining = cap - s;
	if(r >= remaining){
		return {r-remaining, cap};
	}
	else{
		return {0, s+r};
	}
}

void generate(int x, int y, int z){
	int u = get_id(x,y,z);
	int f1 = get_id(A,y,z);
	int f2 = get_id(x,B,z);
	int f3 = get_id(x,y,C);
	int d1 = get_id(0,y,z);
	int d2 = get_id(x,0,z);
	int d3 = get_id(x,y,0);
	pair<int, int> k = t(x,y,b);
	int t1 = get_id(k.first, k.second, z);
	k = t(x,z,c);
	int t2 = get_id(k.first, y, k.second);
	k = t(y,z,c);
	int t3 = get_id(x, k.first, k.second);
	// do this for t6
	adj[u].push_back(f1);
	adj[u].push_back(f2);
	...
	adj[u].push_back(t6);
}

int main()
{
	init_code();

    
    cin>>a>>b>>c;
    for(int i=0; i<= a; i++){
    	for(int j=0; j<=b; j++){
    		for(int k = 0; k<= c; k++){
    			generate(i,j,k);
    		}
    	}
    }

	// int n,m;
	// int u, v;
	// cin>>n>>m;
	// while(m--){
	// 	cin>>u>>v;

	// 	adj[u].push_back(v);
	// 	adj[v].push_back(u);
	// }

	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	int src = 1;
	d[src] = 0;
	vis[src] = 1;
	Q.push(src);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for(auto v : adj[u]) {
			if(vis[v] == 0){
				d[v] = d[u] + 1;
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
    

    return 0;
}

// start of flattened_tree:

int values[100005];
int transformed_values[100005];
vector<int> level_nodes[100005]; // level_nodes[i] represents all the nodes at level i in the tree flattened order.
vector<int> flattened_tree;
int start_pos[100005], end_pos[100005];

void dfs(int node, int par, int h){
	flattened_tree.push_back(node);
	start_pos[node] = flattened_tree.size();
	transformed_values[start_pos[node]] = values[node];
	level_nodes[h].push_back(node);
	for(auto i: child[node]){
		if(i!=par){
			dfs(i,node,h+1);
		}
	}
	end_pos[node] = flattened_tree.size();
}

// suppose if u want to do update/query on subtree of node w
// then update/query on range start_pos to end_pos

void solve(){

	1st update - update value of node W to X.
	update(start_pos[W], X);

	2nd query - query gcd of subtree node values of w
	range(start_pos[W], end_pos[W])
}

// another property of the flattened_tree is that
// nodes from subtree of a node at a given level they are in order

// for ex:
1 1
2 2 7 8
3 3 5 11 12 10
4 6 9 4

// given a node W consider all the nodes in subtree of W at height H
// node - W, height - H 
// level_nodes[H] - but only in (start_pos[W], end_pos[W])
// so all the nodes X i.e 
// start_pos[W] <= start_pos[X] <= end_pos[W]


// next topic is hashing trees - labelled and unlabelled trees 
// problem - check if 2 unlabelled trees have same structure. 

so how to hash 
hash(W) :
  if W is leaf return leaf_hash
  find hash of children - h1 h2 h3
  sort all hashes - inconsistency due to adjacency list
  h2 h4 h1 h3 ...
  my_nodes_hash = (h2 + h4*p + h1*p^2 ...) % mod 
  return my_nodes_hash

//code is 

#define prime       31
#define leaf_hash   27 
#define internal_node_hash 37  

vi adj1[1001], adj2[1001];
set<int> hash_set;
int hash(int node, int par){
	bool is_leaf = 1;
	vector<int> hashes;
	hashes.push_back(internal_node_hash);
	for(auto child:adj1[node]){
		if(child==par) continue;
		is_leaf = 0;
		hashes.push_back(hash(child, node));
	}
	if(is_leaf){
	    hash_set.insert(leaf_hash);
		return leaf_hash;
	}
	sort(hashes);
	int my_hash = 0;
	for(auto hash:hashes){
		my_hash = (my_hash * prime + hash)% mod;
	}
	hash_set.insert(my_hash);
	return my_hash;
} 

hash(root, -1) //calling the fun 

