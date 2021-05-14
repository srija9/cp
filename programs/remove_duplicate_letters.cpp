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

int main(int argc, char const *argv[])
{
    
    init_code();
	string s;
	cin>>s;
	int lastIndex[26] = {0};
	for(int i=0;i<s.size();i++)
	{
		lastIndex[s[i]-'a']++;
	}
	bool seen[26];
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		lastIndex[s[i]-'a']--;
		int c = s[i]-'a';
		if(seen[s[i]]) continue;
		while(!st.empty() && st.top()>s[i] && lastIndex[st.top()-'a']>0)
			{ seen[st.top()] = false;
				st.pop();
			}
		st.push(s[i]);
		seen[s[i]] = true;
	}

    //cout<<st.top();
    string am ="";
    while(!st.empty())
          {
               am = am+st.top();
                st.pop();
          }
          reverse(am.begin(),am.end());
    cout<<am;
		return 0;
}