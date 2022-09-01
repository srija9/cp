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

class node{
public:
	int data;
	node* left;
	node* right;

	//constructor

	node()
	{
		left = NULL;
		right = NULL;
	}

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *tree()
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}

	node *rot = new node(d);
	rot->left = tree();
	rot->right = tree();
	return rot;
}

class BT
{
	public:
	node* root;

	BT();
	//node *tree();
	void disp();
	void display(node*);
	pair<int,int> dia();
	pair<int,int> diameter(node*);
	
};

BT::BT(){
	this->root = tree();
}

void BT::disp(){
	display(this->root);

}

void BT::display(node* no)
{
	//node* no = this->root;

	if(no == NULL){
		return;
	}

	if(no->left == NULL){
		cout<<".";
	}else{
		cout<<no->left->data;
	}
	cout<<" => "<<no->data<<" <= ";
	if(no->right == NULL){
		cout<< ".";
	}else{
		cout<<no->right->data;
	}

	cout<<"\n";

	display(no->left);
	display(no->right);

}

pair<int,int> BT::dia()
{
	return diameter(this->root);
}

bool comp(int a, int b)
{
    return (a < b);
}

pair<int,int> BT::diameter(node* nn)
{
	if(nn == NULL){
		pair<int,int> temp;
		temp.first = -1; //height
		temp.second = 0; //diameter
		return temp;        
	}

	pair<int,int> lf = diameter(nn->left);
	pair<int,int> ri = diameter(nn->right);
	pair<int,int> cur;
	cur.first = max(lf.first, ri.first) +1;
	int ld = lf.second;
	int rd = ri.second;
	int sp = lf.first + ri.first + 2;
	cur.second = max({sp,ld,rd},comp);

	return cur;
}

int main()
{
    init_code();

    BT bt;
    bt.dia();

    cout<<bt.dia().second<<'\n';


    return 0;
}