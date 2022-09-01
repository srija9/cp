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

int p[10000];
// int sz[10000];

int get_root(int u){
	if (p[u] == -1) return u;
	int root_of_u = get_root(p[u]); // we did path compression
	p[u] = root_of_u;
	return root_of_u;
}

void merge(int u, int v) {
	// p[v] = u;
	// if(sz[u] >= sz[v]) {
	// 	p[v]=u;
	// 	sz[u] += sz[v];
	// }else {
	// 	p[u] = v;
	// 	sz[v] += sz[u];
	// }
	if(rand() % 2){
		p[v] = u;
	} else {
		p[u] = v;
	}
}

int main()
{
    init_code();
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
    	p[i] = -1;
    	// sz[i] = 1;
    }
    int q;
    cin>>q;
    while(q--){
    	string qtype;
    	int u,v;
    	cin>>qtype>>u>>v;
    	if(qtype == "M"){
    		int root_of_u = get_root(u);
    		int root_of_v = get_root(v);
    		if(root_of_v == root_of_u){

    		}else {
    			merge(root_of_u,root_of_v);
    		}

    	}
    	else if(qtype == "A") {
    		int root_of_u = get_root(u);
    		int root_of_v = get_root(v);
    		if(root_of_v == root_of_u){
    			cout<<"Yes, they are already belongs to set "<<root_of_u<<"\n";
    		}
    		else{
    			cout<< u <<" belongs to " << root_of_u << " and " << v << " belongs to "<<root_of_v<<"\n";
    		}
    	}
    }

    return 0;
}