//using hashmaps to solve this problem
//problem- list of anagrams.

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

vector<vector<string> > groupAnagrams(string strs[], int len){

	//int al = sizeof(strs)/sizeof(strs[0]);

    vector<vector<string> > res;
    //cout<<al;
	// if(strs.size() == 0){
	// 	return res;
	// }

	unordered_map<string,vector<string> > ans;

	for(int i=0;i<len;i++){
		string s = strs[i];
		sort(s.begin(), s.end());
		if(ans.find(s)==ans.end())
		{
			ans[s]= vector<string>();
		}
		ans[s].push_back(strs[i]);
	}

	
    for(auto r : ans){
    	res.push_back(ans[r.first]);
    }

	return res;

}

int main()
{
    init_code();
    string strs[] = {"eat","tea", "tan", "ate", "nat", "bat"};

    int al = sizeof(strs)/sizeof(strs[0]);
    //cout<<al;

    vector<vector<string> > res = groupAnagrams(strs, al);
    

    for(auto r : res){
    	cout<<"[";
    	for(int i=0;i<r.size();i++){
    		cout<<r[i]<<" ";
    	}
    	cout<<"]"<<endl;
    }

    return 0;
}