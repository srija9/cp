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


void firstNonRepeating(string str)
{
	int count[26]={0};
	std::queue<char> q;

	for(int i=0; i<str.length(); i++)
	{
		char ch = str[i];
		
		q.push(ch);

		count[ch-'a']++;

		while(!q.empty()){
			if(count[q.front()-'a']>1)
				q.pop();
			else{
				cout<<q.front()<<" ";
				break;
			}
		}

		if(q.empty())
		{
			cout<<-1<<" ";
		}
	}
}

int main(int argc, char const *argv[])
{
	init_code();
	string str = "abaccb";
	cout<<str<<"\n";
	firstNonRepeating(str);
	return 0;
}

