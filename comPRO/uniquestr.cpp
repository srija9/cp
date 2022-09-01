//find the length of the largest subsequence with non-repeating characters. given a string 
//using hashset. (Unordered_set in cpp) + sliding window apporach
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

int longestSubstring(string str){
	int len = str.length();

	unordered_set<char> set;

	int ans=0;
	int i=0;
	int j=0;

	while(i<len && j<len){
		if(set.find(str[j])==set.end()){
			set.insert(str[j++]);
			ans = max(ans, j-i);
		}else{
			set.erase(str[i++]);
		}
	}
	return ans;
}

int main()
{
    init_code();

    string str = "abcabcbb";
    cout<<longestSubstring(str);


    return 0;
}

//o/p: 3