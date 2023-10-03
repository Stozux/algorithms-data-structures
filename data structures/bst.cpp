#include <iostream>
using namespace std;

typedef struct bstNode
{
    int key;
    int element;
    bstNode* left;
    bstNode* right;    
}node;

node* create_bst_node(int k, int e)
{
    node* n = (node*) malloc (sizeof(node));
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

typedef struct BST
{
    node* root;
    int nodecount;
}bst;

bst* create_bst()
{
    bst* bstree = (bst*) malloc (sizeof(bst));
    bstree->root = NULL;
    bstree->nodecount = 0;
    return bstree;
}

node* getmin(node* rt)
{
    if (rt->left == NULL)
    {
        return rt;
    }
    return getmin(rt->left);
}

int findhelp(node* rt, int k)
{
    if (rt == NULL)
    {
        return NULL;
    }
    if (rt->key > k)
    {
        return findhelp(rt->left, k);
    } else if (rt->key == k)
    {
        return rt->element;
    } else
    {
        return findhelp(rt->right, k);
    }   
}


int find (bst* bstree, int k)
{
    return findhelp(bstree->root, k);
}

node* deletemin(node* rt)
{
    if (rt->left == NULL)
    {
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;   
}

node* inserthelp(node* rt, int k, int e)
{
    if (rt == NULL)
    {
        return create_bst_node(k,e);
    }
    if (rt->key > k)
    {
        rt->left = inserthelp(rt->left, k, e);
    } else
    {
        rt->right = inserthelp(rt->right, k, e);
    } 
    return rt;   
    
}



void insert (bst* bstree, int k, int e)
{
    bstree->root = inserthelp(bstree->root, k, e);
    bstree->nodecount++;
}



node* removehelp(node* rt, int k)
{
    if (rt == NULL)
    {
        return NULL;
    }
    if (rt->key > k)
    {
        rt->left = removehelp(rt->left, k);
    } else if (rt->key < k)
    {
        rt->right = removehelp(rt->right, k);
    } else
    {
        if (rt->left == NULL)
        {
            return rt->right;
        } else if (rt->right = NULL)
        {
            return rt->left;
        } else
        {
            node* temp = (node*) malloc (sizeof(node));
            temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}


int remove (bst* bstree, int k)
{
    int temp = findhelp(bstree->root, k);
    if (temp != NULL)
    {
        bstree->root = removehelp(bstree->root, k);
        bstree->nodecount--;
    }
    return temp;
}   

void preorder(node* rootnode)
{
    if (rootnode != NULL)
    {
        cout << rootnode->element << " ";
        preorder(rootnode->left);
        preorder(rootnode->right);
    }
}

void inorder(node* rootnode)
{
    if (rootnode != NULL)
    {
        inorder(rootnode->left);
        cout << rootnode->element << " ";
        inorder(rootnode->right);
    }
}



void postorder(node* rootnode)
{
    if (rootnode != NULL)
    {
        postorder(rootnode->left);
        postorder(rootnode->right);
        cout << rootnode->element << " ";
    }
}

int main(){
    bst* arvore = create_bst();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        insert(arvore, no,no);
    }
    cout << "Pre order : ";
    preorder(arvore->root);
    cout << "\nIn order  : ";
    inorder(arvore->root);
    cout << "\nPost order: ";
    postorder(arvore->root);
    
}

