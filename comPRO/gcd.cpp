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

int gcd(int a, int b)
{
	cout<<a<<" "<<b<<endl;
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    init_code();

    int a = 10, b = 15;
    cout << "GCD(" << a << ", "
         << b << ") = " << gcd(a, b)
                        << endl;

    return 0;
}