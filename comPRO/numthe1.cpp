//number theory - sieve 
//

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

//1. for the given number n; which are primes, composite numbers from 1 to n.
bool is_prime[10000007];
int operations = 0;
void sieve(int n)
{
	for(int i=2;i<=n;i++) is_prime[i]=true;
	for(int d=2;d<=n;d++){
		if(is_prime[d]==false) continue;
		for(int num=2*d;num<=n;num+=d){
			//2d 3d 4d ...(n/d)
			is_prime[num] = false;
			operations++;
		}
	}

	cout<<operations<<endl;
}


//2. smallest prime factor of every number from 1 to N
int spf[1000006];
bool is_prime[1000006];
void process_spf_table(int n)
{
	for(int i=2;i<=n;i++) is_prime[i]=true;
	for(int i=1;i<=n;i++) spf[i]=i;

	for(int d=2;d<=n;d++){
		if(!is_prime[d]) continue;
		for(int num=2*d;num<=n;num+=d){
			//2d 3d 4d ...(n/d)
			is_prime[num] = false;
			spf[num] = min(spf[num], d);
		}
	}
	cout<<spf[77]<<endl;
}

//3. prime factorization of evry number from 1 to N
vector<int> primes_list[1000006];
void process_prime_factors(int n){
	for(int i=1;i<=n;i++){
		int d = i;
		while(d!=1)
		{
			primes_list[i].push_back(spf[d]);
			d = d/spf[d];
		}
	}
	for(auto prime: primes_list[54]){
		cout<<prime<<" ";
	}
	cout<<endl;
}

//segmented sieve

//map<int,bool> is_prime;
bool is_prime[1000006];

int closest_strickly_greater_multiple(int l, int d){
	return (l/d+1)*d;
}

int segmented_sieve(int l, int r){
	for(int i=l;i<=r;i++) is_prime[i] = true;
	for(int d=2;d<=1000000;d++){
		if(is_prime[d]==false) continue;
		for(int num=max(2*d, closest_strickly_greater_multiple(l, d)); num<=r; num+=d){
			is_prime[num-l] =  false;
		}
	}	
	cout<<is_prime[14-l]<<endl;
}

// no of divisors for every number in range from l to r
int divisors[1000006];

int closest_greater_multiple(int l, int d){
	return ((l+d-1)/d)*d; //ceil
}

bool is_perfect_square(int n){
	int w=sqrt(n);
	return w*w == n;
}

void segmented_sieve_divisors(int l, int r){
	for(int d=1;d<=1000000;d++){
		for(int num=closest_strickly_greater_multiple(l, d); num<=r; num+=d){
			int d1=d;
			int d2=num/d;
			if(d1<=d2) divisors[num-l]+=2;
		}
	}	
	for(int i=l;i<=r;i++){
		if(is_perfect_square(i)) divisors[i-l]--;
	}
	cout<<divisors[9-l]<<endl;
}

void solve(){
	process_spf_table(1000006);
	process_prime_factors(1000006);

}

int main()
{
    init_code();

    return 0;
}