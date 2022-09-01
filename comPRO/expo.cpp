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

bool is_set(int num, int idx){
	return (num & (1 << idx));  //1<<0 is 1 left shift
}

int expo(int a,int n){
	int ans = 1;
	int e = a;

	for(int i=0;i<31;i++)    // 32 bit so 32 times..
	{
		if(is_set(n,i)){
			ans = ans*e;
		}
		e = e*e;
	}
	return ans;
}

//optimise code 

int expo1(int a,int n){
	int ans=1;
	int e = a;

	while(n>0){
		if(n%2 == 1){ // if (n&1)
			ans=ans*e;
		}
		n=n/2; //n>>=1
		e=e*e;
	}
	return ans;
}


//using modulo

const int modd = (int)1e9+7;

int expo2(int a,int n){
	int ans=1;
	long long int e = a;

	while(n>0){
		if(n%2 == 1){ // if (n&1)
			ans=ans * e % modd;
		}
		n=n/2; //n>>=1
		e=e * e % modd;
	}
	return ans;
}

//how to cal modular inverse

int mod_inverse(int a){
	return expo2(a, mod-2); // this can done in log n times
}

int main()
{
    init_code();
     
     int a;
     cin>>a;
    while(a--){
    	int a,n;
    	cin>>a>>n;
    	cout<<expo(a,n)<<endl;
    }
     

    return 0;
}

