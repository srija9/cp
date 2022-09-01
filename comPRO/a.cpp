 #include <bits/stdc++.h>
using namespace std;
 
// Function to find precedence of
// operators.
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

int maxD = -1 , maxNode = -1 ;

int vis[100000];

void DFS( vector<int> graph[] , int node , int d )
{
    // marking the node as visited
    vis[node] = 1 ;


    // if the distance from root is greater then maximum Distance then updating the maximum value of distance
    // also storing the maxNode no. as this node is now at the farthest distance
    if( d > maxD )
    {
        maxNode = node ;
        maxD = d ;
    }

     // applying the standard dfs 
    for( auto x : graph[node] )
    {
        if( vis[x] == 0 )
        {
            DFS( graph , x , d+1 ) ;
        }
    }

    


}

int main(){
    init_code();
    int t;
    cin>>t;
    while(t--)
    {
        int graph1, graph2;
        vector<int> tree1[graph1], tree2[graph2];

        cin>>graph1;
        int from,to;
        for(int i=0;i<graph1;i++)
        {
            cin>>from>>to;
            tree1[from].push_back(to);
            tree1[to].push_back(from);
        }
        // cin>>graph2;
        // for(int i=0;i<graph2;i++)
        // {
        //     cin>>from>>to;
        //     tree2[from].push_back(to);
        //     tree2[to].push_back(from);
        // }

        DFS( tree1 , 1 , 1 ) ;
     // we could have choosen any node in the graph but for simplicity we have choosen node 1

     
     // making every node unvisited as we will be applying DFS
     maxD = -1 ;
     for( int i = 1 ; i<=graph1 ; i++ )
     {
         vis[i] = 0 ;
     }
     
     // applying the dfs for the second time as this will give the diameter of the tree
     DFS( tree1 , maxNode , 1  ) ;


     // Now printing the maximum diameter of the tree
     cout<<maxD<<" is the diameter of the tree "<<endl;

       
    }
}