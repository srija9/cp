#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"

//sort:  sort(startadd,endadd) endadd=the add of the next contiguous loc of the last element.
//binary search : binary_search(startadd, endadd, valuetofind) returuns true & false..
//reverse: reverse(first_iterator,last_iterator) same as sort


void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void show(int a[], int array_size)
{
	for (auto i = 0; i < array_size; ++i)
		cout << a[i] << " ";
}


int main()
{
	init_code();
	  
	int a[] = { 5, 10, 15, 20, 20, 23, 42, 45};
   	// size of the array
	int asize = sizeof(a) / sizeof(a[0]);
	vector<int> v;
	v.assign(5,10);
	v.insert(v.begin()+1,5);
	sort(v.begin(),v.end());
	auto q = lower_bound(v.begin(),v.end(),20);
	cout<<q-v.begin()<<endl;
	//cout << "The array before sorting is : \n";
    
    //show(v,v.size());
    for(auto i=v.begin();i!=v.end();i++)
    {
    	cout<<*i<<" ";
    }
    cout<<endl;
    //sort(a, a + asize);
    //show(a,asize);

	return 0;
}