//given the array of ints, need to find the no of continous subarrays whose sum is ==k (int)
// using hashmap, application of perfix sum and sum diff which is equal to k. 

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

int subarray_Sum(int arr[], int len, int k){

	int count=0;
	int sum = 0;

	// int al = sizeof(arr)/sizeof(arr[0]);
	// cout<<al;

	unordered_map<int, int> map;
	map[0]=1;

	for(int i=0; i<len;i++){
		sum += arr[i];

		if(map.find(sum-k)!=map.end()){
			count += map[sum-k];
		}

		if(map.find(sum)!=map.end()){
			map[sum]++;
		}else{
			map[sum]=1;
		}
	}

	return count;
}

int main()
{
    init_code();

    int arr[] = {3,4,7,2,-3,1,4,2};

    int al = sizeof(arr)/sizeof(arr[0]);
    

    cout<<subarray_Sum(arr, al, 7); //k=3

    return 0;
}