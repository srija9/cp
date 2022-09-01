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

int run_bfs(int s, vector<bool> & visited,  vector<vector<int> > &adjList){
    queue<bool> Q;
    visited[s] = true;
    int node_count = 0;
    while(!Q.empty())
    {
        s = Q.front(); Q.pop();
        node_count +=1;

        for(int adjNode: adjList[s]) if(!visited[adjNode]){
            visited[adjNode] = true;
            Q.push(adjNode);
        }
    }
    return node_count;
}

int inTime[1000];
int outTime[1000];

int inT = 0, ouT = 0;

int dfs(int s, vector<bool> &visited, vector<vector<int> > &adjList)
{
    visited[s] = true;
    inTime[s] = inT++;
    for(int adjNode:adjList[s]) if(!visited[adjNode]){
        dfs(adjNode, visited, adjList);
    }
    outTime[s] = ouT++;
}

int main()
{
    init_code();

    int n; // no of vertices
    int m; // no of edges

    cin>>n;
    cin>>m;

   // vector<vector<int> > adjMat(n, vector<int> v(n,0)); // adjMat [n][n]
    vector<vector<int> > adjList(n);

    for(int i=0;i<m;i++)
    {
    	int from, to;
    	cin >> from >> to;
    	//adjMat[from][to] = 1;

        adjList[from].push_back(to);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<< "AdjList of " << i << ": ";
    //     for(int nd: adjList[i]) cout<< nd << ", ";
    //     cout<<"\n";
    // }

    // Do bfs from source node

    const int INF = 100000000;

    vector<bool> visited(n, false);


     // now the graph is given and we need to find the connecting components
     // in it so we use run_bfs()

    int conn_comp_count = 0;
    for(int nd=0; nd<n; nd++) if(!visited[nd]) {
        //run a bfs 
        conn_comp_count++;
        int node_count = run_bfs(nd,visited, adjList);
        cout<<"we ran a BFS from "<< nd << ", node_count = " << node_count<<"\n";
    }

    cout<< "\n Total "<< conn_comp_count<<" connected componenets found";


    /*
    vector<int> entryTime(n, INF);
    vector<int> dist(n, INF);

    //to find BFS we used here 2 ways and 1st one is using 
    // the enttry time and 2nd is using the queue 

    int t = 0;
    int s = 0;
    visited[s] = true;
    entryTime[s] = t; t++;
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    while(!Q.empty())
    {
        //this is queue method also used to find the distance b/w root and particular node

        s = Q.front(); Q.pop();
        cout<<"We're at node = "<<s<<"\n";
        for(int adjNode: adjList[s]) if(!visited[adjNode]) {
            visited[adjNode] = true;
            dist[adjNode] = dist[s] + 1;
            Q.push(adjNode);
        }
    }
    */

    // for(int tm=0; tm<n; ++tm){
    //     //tm: entry time of the node from
    //     // where we are going to do the BFS now.
    //     s=-1;
    //     for(int nd=0;nd<n;++nd)
    //     {
    //         if(entryTime[nd] == tm){
    //             s = nd;
    //             break; 
    //         }
    //     }

    //     if(s==-1) break;

    //     for(int adjNode: adjList[s]) if(!visited[adjNode]) {
    //         visited[adjNode] = true;
    //         entryTime[adjNode] = t; t++;
    //     }
    // }
    
      


    return 0;
}