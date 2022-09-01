#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define ordered_set tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N = 200005;
#define M 1000000007
#define BINF 1e9
#define init(arr, val) memset(arr, val, sizeof(arr))
#define MAXN 501
#define deb(xx) cout << #xx << " " << xx << "\n";
const int LG = 22;

vector<int> adj[N];
int timer = 0, st[N], en[N], lvl[N], P[N][LG];

void dfs(int node, int parent)
{
    lvl[node] = 1 + lvl[parent];
    P[node][0] = parent;

    st[node] = timer++;
    for (int i : adj[node])
    {
        if (i != parent)
        {
            dfs(i, node);
        }
    }
    en[node] = timer++;
}

void pre(int u, int p)
{
    P[u][0] = p;
    for (int i = 1; i < LG; i++)
        P[u][i] = P[P[u][i - 1]][i - 1];

    for (auto i : adj[u])
        if (i != p)
            pre(i, u);
}

int lca(int u, int v)
{
    int i, lg;
    if (lvl[u] < lvl[v])
        swap(u, v);

    for (lg = 0; (1 << lg) <= lvl[u]; lg++)
        ;
    lg--;

    for (i = lg; i >= 0; i--)
    {
        if (lvl[u] - (1 << i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
        return u;

    for (i = lg; i >= 0; i--)
    {
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}

void add_edge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void solve()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        st[i] = en[i] = lvl[i] = 0;
        for (int j = 0; j < LG; j++)
        {
            P[i][j] = -1;
        }
    }
    timer = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }

    dfs(1, 0);
    pre(1, 0);

    cout << "start time\n";

    for (int i = 1; i < 7; i++)
    {
        cout << st[i] << " ";
    }

    cout << "\nend time\n";

    for (int i = 1; i < 7; i++)
    {
        cout << en[i] << " ";
    }

    cout << "\n";

    int q;
    cin >> q;

    while (q--)
    {

        int k;
        cin >> k;

        assert(k >= 1 and k <= n);

        vector<int> path(k);
        for (int i = 0; i < k; i++)
        {
            cin >> path[i];
        }

        vector<pair<int, int>> v;
        for (auto i : path)
        {
            v.push_back(make_pair(st[i], i));
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].F << " -> " << v[i].S << " -> " << en[v[i].S] << endl;
        }

        vector<int> node;

        for (int i = 0; i < k; i++)
        {
            bool got = false;
            cout << i + 1 << " " << en[v[i + 1].S] << " < " << en[v[i].S] << " " << v[i].S << " " << v[i + 1].S << " done " << endl;
            if (i + 1 < k and en[v[i + 1].S] < en[v[i].S])
            {
                got = true;
            }
            // cout<<got<<endl;
            if (!got)
            {
                node.push_back(v[i].S);
            }
        }

        for (int i = 0; i < node.size(); i++)
        {
            cout << node[i] << endl;
        }

        cout << node.size() << " ";

        if (node.size() > 2)
        {
            cout << "NO\n";
            continue;
        }
        if (node.size() == 1)
        {
            cout << "YES\n";
            continue;
        }

        assert(node.size() == 2);

        int lca_node = lca(node[0], node[1]);

        int ok = 1;

        for (auto i : path)
        {
            if (i != lca_node and lvl[lca_node] >= lvl[i])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}