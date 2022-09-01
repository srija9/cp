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



int main() {
    init_code();
    // your code goes here
    int t;
    cin>>t;
    int l,h,i;
    while(t--)
    {
        int count=0,f=0;
        cin>>l>>h;
        string s;
        cin>>s;
        //cout<<s;
       // cout<<h<<" ";

        for(i=0;i<l;i++)
        {
            if(s[i]=='0')
            {
                count++;
            }
            //cout<<count<<" ";

            
            if(count!=0 && s[i]=='1')
            {
                h=2*(h-count);
                count = 0;
                
            }

            // cout<<"h value is "<<h<<endl;
            // cout<<"count value is "<<count<<endl;

            if(count == h)
            {
                f = 1;
                break;
            }
            //cout<<" "<<count<<" ";
        }
        cout<<f<<" ";
        if(f==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}