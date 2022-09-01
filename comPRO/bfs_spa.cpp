#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod            1000000007
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

vector<int> child[1000];

int main()
{
    init_code();
    int n = 100;
    for (int i = 0; i < n; i++) {
    	int cn; //scanned from input
    	for (int j = 0; j < cn; j++) {
    		int child_of_i; // should be scanned from input
    		child[i].push_back(child_of_i);
    	}
    }
    int source; // scanned from input
    queue<int> Q;
    vector<int> d(n, mod);

    Q.push(source);
    d[source] = 0;

    while(!Q.empty()) {
    	int root = Q.front();
    	Q.pop();
    	for (int c: child[root]) if (d[c] !=  mod) {
    		Q.push(c);
    		d[c] = d[root] + 1;
    	}
    }

    for (int i = 0; i < n; i++) {
    	printf("Distance of %d from source(%d) = %d\n", i, source, d[i]);
    }

    return 0;
}