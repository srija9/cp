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
	// node(int d)
	// {
	// 	data = d;
	// 	left=NULL;
	// 	right=NULL;
	// }

};

class BinaryTree{
	node* root;
    int size;
public:
	BinaryTree();
	node* takeInput(node*,bool);
	void display();
	void display(node*);
};

BinaryTree::BinaryTree()
{
	this->root = takeInput(NULL, true);

}

node* BinaryTree::takeInput(node* parent, bool ilc)
{
	if(parent == NULL){
		cout<<"Root node data?\n";
	}else{
		if(ilc){
			cout<<"enter the value of the left child of "<< parent->data <<'\n';
		}else{
			cout<<"enter the value of the right child of "<< parent->data <<'\n';
		}
	}

	node *ptr = new node;
	int data;
	cin>>data;
	ptr->data = data;

	this->size++;

	cout<<ptr->data << " has left child?\n";
	bool hlc;
	cin>>hlc;

	if(hlc){
		ptr->left = takeInput(ptr, true);
	}

	cout<<ptr->data << " has right child?\n";
	bool hrc;
	cin>>hrc;

	if(hrc){
		ptr->right = takeInput(ptr, false);
	}

	return ptr;

}

void BinaryTree::display(){
	cout<<"---------------------";
	display(this->root);
	cout<<"---------------------";

}

void BinaryTree::display(node* no)
{
	
	if(no == NULL){
		return;
	}

	string str="";
	if(no->left == NULL){
		str+= ".";
	}else{
		str+= no->left->data;
	}

	str += "=> ";
	str += no->data;
	str += " <=";

	if(no->right == NULL){
		str += ".";
	}else{
		str += no->right->data;
	}

	cout<<str;

	

	display(no->left);
	display(no->right);
}



int main()
{
    //init_code();
    BinaryTree bt;
    bt.display();

    return 0;
}