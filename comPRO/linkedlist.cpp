#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

class Node
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        this.data = d;
        this.next = NULL;
    }
}

class ll
{
    Node *head;

    void addAtFirst(int);
}

ll::addAtFirst(int data)
{
    node *ptr = new Node(data);
    ptr->next = head;
    head = ptr;

}


int main(int argc, char const *argv[])
{
init_code();
int n;
cin>>n;
stack<int> s;
list<int> lll;
cout<<"you have entered "<<n<<endl;
return 0;
}