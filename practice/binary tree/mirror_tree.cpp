#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

typedef struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
}node;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<" "<<root->val;
    inorder(root->right);
}

void mirrorify(node* root, node** mirror){

    if (root == NULL) {
        mirror = NULL;
        return;
    }

    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}

treenode* mirrorTree(node* root){
    if(root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;

    if(root->left)
        mirrorTree(root->left);
    if(root->right)
        mirrorTree(root->right);

    return root;
}
 
int main(int argc, char const *argv[])
{
    //init_code();
    node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    inorder(tree);
    node* mirror = NULL;
    mirrorify(tree, &mirror);
    inorder(mirror);
    mirrorTree(tree);
    inorder(tree);
   
   return 0;
}