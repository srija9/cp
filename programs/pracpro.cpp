#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
#define endl 		   "\n"
#define mid(l,r)	   (l+(r-1)/2)
#define loop(i,a,b)	   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) for(int i=(a);i>=(b);i--)

void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void f(const vector < int > & v){
	
	for(vector<int> ::const_iterator it = v.begin(); it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
	
}


int main(int argc, char const *argv[])
{
	init_code();
	// float n=389067.6145678;
 //    double k = log10(n);
 //    k=k-floor(k);
    //int x= pow(10,k);
    //cout<<x;
    //int y = floor(log10(n)) + 1;
    //auto y=0b111;  
    // cout<<y+1;
    
    vector<int> v(5);
    loop(i,1,5)
    {
    	v.push_back(i);
    }
    
    //f(v);

    // pair <string, pair<int, int>>p;
    // string s = p.first;
    //int x = p.second.first;
    // int y = p.second.second;

    //x = 2;
    //y=5;
    //s = "srija";
   // cout<<s<<x<<y;
     
     set<int>s;
     for(int i=1;i<=100;i++){
     	s.insert(i);
     }
     
     s.insert(42);
     // int n=int(s.size());
     // cout<<n;
     for(int i=2;i<=100;i+=2){
     	s.erase(i);
     }

     int n=int(s.size());
     cout<<n;
	return 0;
}
