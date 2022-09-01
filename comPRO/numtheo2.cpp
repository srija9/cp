// number theory :- CF solider and number game

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

int num_of_primes[5000006];
int spf[5000006];
bool is_prime[5000006];
int num_of_primes_in_factorial[5000006];

void process_spf(){
	for(int i=1;i<=5000000;i++) is_prime[i] = true;
	for(int i=1;i<=5000000;i++) spf[i]=i;
	for(int d=2;d<=5000000;d++){
		if(is_prime[d]==false) continue;
		for(int num=2*d;num<=5000000;num+=d){
			is_prime[num]=false;
			spf[num]=min(spf[num],d);
		}
	}
}

void process_num_of_primes(){
	for(int i=1;i<=5000000;i++){
		int num=i;
		while(num!=1){
			num_of_primes[i]++;
			num = num/spf[num];
		}
	}
}

void solve(){
	process_spf();
	process_num_of_primes();
	for(int i=1;i<=5000000;i++){
		num_of_primes_in_factorial[i] = num_of_primes[i] + num_of_primes_in_factorial[i-1];
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = num_of_primes_in_factorial[a] - num_of_primes_in_factorial[b];
		cout<<ans<<endl;
	}
}

int main()
{
    init_code();
    solve();
    return 0;
}

//input 
// 2
// 3 1
// 6 3
//output
// 2
// 5