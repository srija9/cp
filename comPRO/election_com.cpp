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

const ll INF = 1000000009LL * 10009LL;

bool on_path[100];

ll find_distance(vector<vector<ll> > &d, int n) {
	ll total_ds = 0;
	for(int i = 0; i < n; i++) {
		if(!on_path[i]) {
			ll ds = INF;
			for(int j = 0; j < n; j++) if(on_path[j]) {
				ds = min(ds, d[i][j]);
			}
		}
		total_ds += ds;
	}
	return total_ds;
}

ll solve(int n) {
	vector<int> special_nodes;
	vector<vector<ll> > d(n, vector<ll>(n, INF));
	for(int i = 0; i < n; i++) {
		int is_special, m;
		cin >> is_special >> m;
		if(is_special) special_nodes.push_back(i);
		while(m--) {
			int j, c;
			cin >> j >> c;
			j--;
			d[i][j] = d[j][i] = c;
		}
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for( int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
		}
	}

	int sn = special_nodes.size();
	ll final_ans = INF;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < sn; j++) {
			memset(on_path, 0, 100);
			int s1 = special_nodes[i], s2 = special_nodes[j];
			on_path[s1] = on_path[s2] = 1;
			for(int k = 0; k < n; k++) {
				if(d[s1][k] + d[k][s2] == d[s1][s2]) on_path[k] = 1;
			}
			ll dis = find_distance(d, n);
			final_ans = min(final_ans, dis);
		}
	}
	return final_ans;
}

int main()
{
    init_code();

    int T, n;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
    	cin >> n;
    	ll ans = solve(n);
    	cout << "Case " << tc << ans <<'\n';
    }

    return 0;
}