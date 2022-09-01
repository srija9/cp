#include <bits/stdc++.h>
#include<array>
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
	// int hdis = 0;

	// map<int, vector<int> >m;

	BT();
	//node *tree();
	BT(int [],int []);
	void disp();
	void display(node*);
	//using pre-order and in-order
	node* construct(int[], int[],int,int,int,int);
	void printLO();
	void printLevelOrder(node*);
	void printVO(int,map<int, vector<int> > &);
	void printVerticalOrder(node*, int, map<int, vector<int> > &);
};

BT::BT(){
	this->root = tree();	
}

BT::BT(int pre[],int in[])
{
	this->root = construct(pre, in, 0, 7, 0, 7);

}

node* BT::construct(int pre[],int in[], int plo, int phi, int ilo, int ihi)
{
	if(plo>phi || ilo>ihi){
		return NULL;
	}

	node *nn = new node();
	nn->data = pre[plo];

	int si = -1;
	for(int i=ilo; i<=ihi; i++){
		if(pre[plo]==in[i]){
			si = i;
			break;
		}
	} 

	int nel = si - ilo;

	nn->left = construct(pre, in, plo+1, plo+nel, ilo, si-1);
	nn->right = construct(pre, in, plo+nel+1, phi, si+1, ihi);

	return nn;
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

void BT::printLO(){
	printLevelOrder(this->root);
}

void BT::printLevelOrder(node* rot){
	if(rot == NULL){
		return;
	}

	queue<node*> q;
	q.push(rot);
	q.push(NULL);

	while(!q.empty()){
		node* nod = q.front();
		q.pop();
		if(nod!=NULL){
			cout<<nod->data<<" ";
			if(nod->left)
				q.push(nod->left);
			if(nod->right)
				q.push(nod->right);
		}
		else if(!q.empty())
		{
			q.push(NULL);
		}

	}
}

void BT::printVO(int hdis, map<int, vector<int> > &m){
	printVerticalOrder(this->root, hdis, m);
}

void BT::printVerticalOrder(node* rot, int hdis, map<int, vector<int> > &m){

	if(rot == NULL)
		return;

	m[hdis].push_back(rot->data);
	printVerticalOrder(rot->left, hdis-1, m);
	printVerticalOrder(rot->right, hdis+1, m);

}

int main()
{
    init_code();

    BT bt;
    //bt.disp();
    //bt.printLO();


    int hdis = 0;

	map<int, vector<int> >m;

	bt.printVO(hdis, m);

	map<int, vector<int> > :: iterator it;

	for(it = m.begin(); it != m.end(); ++it)
	{
		for(int i=0; i<(it->second).size();i++)
		{
			cout<<(it->second)[i] << " ";
		}
		cout<<endl;
	}

    // int pre[] = {10,20,40,50,60,70,30,80};
    // int in[] = {40,20,60,50,70,10,80,30};

    // BT bt(pre,in);
    // bt.disp();

    return 0;
}

// input: 
// 1 2 3 -1 4 -1 -1 -1 5 -1 -1

// output:
// 2 =>1 <=5
// 3 =>2 <=.
// . =>3 <=4
// . =>4 <=.
// . =>5 <=.

// input: 
// int pre[] = {10,20,40,50,60,70,30,80};
// int in[] = {40,20,60,50,70,10,80,30};

// output:
// 20 => 10 <= 30
// 40 => 20 <= 50
// . => 40 <= .
// 60 => 50 <= 70
// . => 60 <= .
// . => 70 <= .
// 80 => 30 <= .
// . => 80 <= .

// output: vertical order:
// 3 
// 2 4 
// 1 
// 5 
