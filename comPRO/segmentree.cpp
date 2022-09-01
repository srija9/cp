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

int inp[100010];

struct node {
	int l, r;
	int value;
} segtree[100000];

void build_segtree(int u, int l, int r) {
	// break condition
	if(l == r) {
		segtree[u].value = inp[l];
		segtree[u].l = l;
		segtree[u].r = r;
		return ;
 	}

 	int m = (l+r)/2, lft = 2 * u, rgt = 2*u + 1;
 	build_segtree(lft, l, m);
 	build_segtree(rgt, m+1, r);

 	segtree[u].value = segtree[lft].value + segtree[rgt].value;
 	segtree[u].l = l;
 	segtree[u].r = r;
}

int seg_query(int u, int l, int r) { // [l, r] is the original query
	// if the range of node u is completely inside the [l-r] then take it 
	if (l <= segtree[u].l && segtree[u].r <= r) {
		return segtree[u].value;
	}
	// if there is no overlap then just return 0
	if (segtree[u].l > r or segtree[u].r < l) {
		return 0;
	}

	return seg_query(2*u, l, r) + seg_query(2*u+1, l, r);
}

void update_segtree(int u, int idx, int val) {
	// this node contains the information of segtree[u].l and segtree[u].r 
	//if this range contains idx then we need to update it 
	if (segtree[u].l <= idx && segtree[u].r >= idx)
	{
		//this is leaf?
		if(segtreee[u].l == segtree[u].r) {
			segtree[u].value += val;
			return ;
		}
		else {
			int lft = 2*u, rgt = 2*u + 1;
			update_segtree(lft, idx, val);
			update_segtree(rgt, idx, val);
			//this is MERGE operation.
			segtree[u].value = segtree[lft].value + segtree[rgt].value;
		}
	}
	else return;
}

int main()
{
    init_code();
    int n; // length of the array
    cin>>n;
    
    for(int i = 1; i <= n; i++) {
    	// read the input value of the array
    	cin>> inp[i]; 
    }

    // build the segment segtree

    build_segtree(1, 1, n);

    // process the queries
    int Q;
    cin >> Q;
    while(Q--) {
    	string type;
    	cin >> type;
    	if( type == 'A') {
    		int l, r;
    		cin >> l >> r;
    		int ans = seg_query();
    		cout << ans << "\n";
    	}

    	if (type == 'U') {
    		int idx, val;
    		cin >> idx >> val;

    		update_segtree(1, idx, val);
    	}
    }

    return 0;
}