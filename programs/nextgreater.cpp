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

void NGEQ(int arr[],int length){
	stack<int> s;
	s.push(arr[0]);
	for(int i=1;i<length;i++){

		int next=arr[i];
		if(!s.empty()){
			int element = s.top();
			s.pop();
			while(element<next){
				cout<<element << " -> " << next<<endl;
				if(s.empty()){
					break;
				}
				element = s.top();
				s.pop();
			}

			if(element>next){
				s.push(element);
			}
		}
		s.push(next);
	}

	while(!s.empty()){
		int element = s.top();
		s.pop();
		int next = -1;
		cout<<element << " -> " << next<<endl;
	}
}


int main(int argc, char const *argv[])
{
	init_code();
	
    int arr[] = {11, 4, 3, 10,12};
    NGEQ(arr, 5);

	return 0;
}
