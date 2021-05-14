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

//std::array
// Syntax: std::array<T,N> arr;
//access elements:
//  a.at()
//  b.[]
//  c.front()
//  d. back()
//  e. data()//give access to the underlying array

//vec.reserve(1000)

//container inside container

//map:
// 1. map<T1, T2> obj;
// 2. it is implement using self-balanced binary search tree. 

//Topic: multimap
//here keys can be repeated.

class Person{
public:
	float age;
	string name;
bool operator <(const Person& rhs) const { return age<rhs.age;}	
bool operator >(const Person& rhs) const { return age>rhs.age;}	
};

int main(int argc, char const *argv[])
{
	init_code();
	vector<vector<int> > Tree;
	int edge, n1, n2;
    
    //cin>>edge;
    Tree.resize(edge);

    for(int i=0;i<edge;++i)
    {
    	cin>>n1>>n2;
        Tree[n1].push_back(n2);
    }

    // for(const auto &e1:Tree){
    // 	for(const auto &e2: e1){
    // 		cout<<e2;
    // 	}
    // 	cout<<endl;
    // }

    map<string,int, std::greater<>> Map;
    Map["hey"] = 123;
    Map.insert(make_pair("Bot",456));

    for(auto &el1:Map){
    	cout<<el1.first<<" "<<el1.second<<endl;
    }
     

    //if std::vector<char> v;
    std::map<string, vector<int>> map1;
    map1["chotu"].push_back(567);
    map1["amit"].push_back(890);

    for(auto &el1:map1){
    	cout<<el1.first<<endl;
    	for(auto &el2:el1.second){
    		cout<<el2<<" ";
    	}
    	cout<<endl;
    } 
  
    set<Person, std::greater<>> Set={{30,"rupesh"},{25,"hitesh"},{22,"jhon"}};
    for(const auto& e:Set){
    	cout<<e.age<<" "<<e.name<<endl;
    }
    

	return 0;
}
