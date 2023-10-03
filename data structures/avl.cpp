#include <iostream>
using namespace std;

typedef struct bstNode
{
    int key;
    int element;
    int height;
    bstNode* left;
    bstNode* right;    
}node;

node* create_bst_node(int k, int e)
{
    node* n = (node*) malloc (sizeof(node));
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    n->height = 0;
    return n;
}

node* getmin(node* rt)
{
    if (rt->left == NULL)
    {
        return rt;
    }
    return getmin(rt->left);
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

typedef struct BST
{
    node* root;
    int nodecount;
}bst;

int h(node* rt)
{
    if (rt == NULL)
    {
        return -1;
    }
    return rt->height;
}

int getbalance(node* rt)
{
    if (rt==NULL)
    {
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

node* rightrotate(node* rt)
{
    node* l = (node*) malloc (sizeof(node*));
    node* lr = (node*) malloc (sizeof(node*));
    l = rt->left;
    lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

node* leftrotate(node* rt)
{
    node* r = (node*) malloc (sizeof(node*));
    node* rl = (node*) malloc (sizeof(node*));
    r = rt->right;
    rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left),h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

bst* create_bst()
{
    bst* bstree = (bst*) malloc (sizeof(bst));
    bstree->root = NULL;
    bstree->nodecount = 0;
    return bstree;
}


int findhelp(node* rt, int k)
{
    if (rt == NULL)
    {
        return -1;
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
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getbalance(rt);
    if (balance < -1 && k >= rt->right->key)
    {
        return leftrotate(rt);
    }
    if (balance > 1 && k < rt->left->key)
    {
        return rightrotate(rt);
    }
    if (balance > 1 && k >= rt->left->key)
    {
        rt->left = leftrotate(rt->left);
        return rightrotate(rt);
    }
    if (balance < -1 && k < rt->right->key)
    {
        rt->right = rightrotate(rt->right);
        return leftrotate(rt);
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
    if (temp != -1)
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
        cout << rootnode->element << "\n";
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
