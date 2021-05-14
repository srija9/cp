#include<bits/stdc++.h>
using namespace std;




int main(int argc, char const *argv[])
{

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

