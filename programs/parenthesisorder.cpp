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

bool isValid(string str){
	stack<char> s;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(ch=='(' || ch=='{'|| ch=='['){
			s.push(ch);
		}
		else{
			if(s.empty()){
				return false;
			}

			char p = s.top();
			if(ch==')'&& p!='(') return false;
			else if(ch==']' && p!='[') return false;
			else if(ch=='}'&& p!='{') return false;
			else
				s.pop();
		}
	}

	return s.empty();
}


int main(int argc, char const *argv[])
{
	init_code();
	string str="{[()]()";

   cout<<isValid(str);


	return 0;
}
