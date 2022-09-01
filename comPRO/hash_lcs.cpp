//longest consecutive sequence using hashmap
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

int main()
{
    init_code();

    int arr[] = {2,12,4,16,10,5,3,20,25,11,1,8,6,9,13,15,14};

    unordered_map<int, bool> map;

    int al = sizeof(arr)/sizeof(arr[0]);

    //cout<<al<<endl;
    
    for(int i=0; i<al;i++){
    	//check if n-1 is present inthe hashmap.
    	int nm1 = arr[i]-1;
    	if(map.find(nm1)!=map.end())
    	{
    		map[arr[i]] = false;
    	}
    	else{
    		map[arr[i]] = true;
    	}

    	//if current no is a start of a seq, then n+1 cannot be a start 
    	int np1 = arr[i] + 1;
    	if(map.find(np1)!=map.end())
    	{
    		map[np1] = false;
    	}
    }

    std::vector<int> v;
    for(auto const& i:map)
    	v.push_back(i.first);
    
    int maxLength = 0;
    int maxStatingNo = 0;

    for(int key:v){
    	if(map[key]==true){
    		int pstartingNo = key;
    		int count = 0;
    		while(map.find(pstartingNo+count)!=map.end()){
    			count++;
    		}

    		if(count>maxLength){
    			maxLength = count;
    			maxStatingNo = pstartingNo;
    		}
    	}
    }

    //int a[];
    //cout<<maxLength;
    for(int i=1;i<=maxLength;i++){
    	cout<<maxStatingNo<<" ";
    	maxStatingNo++;
    }

    return 0;
}