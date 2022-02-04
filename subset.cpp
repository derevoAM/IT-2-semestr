#include <iostream>
#include <cmath>
using namespace std;

struct subset_node {
	int key;
	subset_node *left;
	subset_node *right;
};

bool fnd(subset_node *c, int k)
{
    if(k > c->key)
    {
        if(c->right == nullptr)
        {
            subset_node *b = new subset_node;
            b->key = k;
            b->left = nullptr;
            b->right = nullptr;
            c->right = b;
            return true;
        }
        else return fnd(c->right, k);
    }
    else if(k < c->key)
    {
        if(c->left == nullptr)
        {
            subset_node *b = new subset_node;
            b->key = k;
            b->left = nullptr;
            b->right = nullptr;
            c->left = b;
            return true;
        }
        else return fnd(c->left, k);
    }
    else return false;
}


bool init(subset_node **sn)
{
    (*sn) = nullptr;
    return true;
}


bool insert(subset_node **sn, int k)
{
    if((*sn) == nullptr)
    {
        (*sn) = new subset_node;
        (*sn)->key = k;
        (*sn)->left = nullptr;
        (*sn)->right = nullptr;
    }
    else
    {
        return fnd(*sn, k);
    }
    return true;
}



unsigned int i = 0;
void dfs(subset_node *sn)
{
    if(!sn) return;
    //cout << sn->key;
    i ++;
    dfs(sn->left);
    dfs(sn->right);
}

unsigned int size(subset_node *sn)
{
    i = 0;
    dfs(sn);
    return i;
}

unsigned int ma = 0;
void dfsheight(subset_node *sn, unsigned int i)
{
    if(!sn)
    {
        ma = max(ma, i);
        //cout << "haha";
        return;
    }

    i ++;
    dfsheight(sn->left, i);
    dfsheight(sn->right, i);
}


unsigned int height(subset_node *sn)
{
    ma = 0;
    dfsheight(sn, 0);
    return ma;
}


subset_node* find(subset_node *sn, int k)
{
    if((sn) == nullptr) return nullptr;
    subset_node *c = sn;
    if(k == c->key) return c;
    if(k > c->key)
    {
        if(c->right == nullptr)
        {
            return nullptr;
        }
        else return find(c->right, k);
    }
    else if(k < c->key)
    {
        if(c->left == nullptr)
        {
            return nullptr;
        }
        else return find(c->left, k);
    }
}

bool remove_void(subset_node *c, int k)
{
    /*if(c == nullptr) return false;
    if(k == c->key)
    {
        if(c->right == nullptr && c->left == nullptr)
        {
            delete c;
            cout << "haha";
            return true;
        }
        else
        if(c->right == nullptr && c->left != nullptr)
        {
            subset_node *b;
            b = c->left;
            delete c;
            c = b;
            return true;
        }
        else
        if(c->right != nullptr && c->left == nullptr)
        {
            subset_node *b;
            b = c->right;
            delete c;
            c = b;
            return true;
        }
    }
    else if(k > c->key)
    {
        return remove_void(c->right, k);
    }
    else if(k < c->key)
    {
        return remove_void(c->left, k);
    }*/
    cout << endl;
    cout << c->key << endl;
    if(c->key == k)
    {
        subset_node *b;
        b = c->right;
        delete c;
        c = b;
        cout << c->key << endl;
    }
    return true;
}

void print_tree(subset_node *c)
{
    if(!c) return;
    cout << c->key << " ";
    print_tree(c->left);
    print_tree(c->right);
}

bool remove(subset_node **sn, int k)
{
    if(find(*sn, k) == nullptr) return false;
    else
    {
        if((*sn)->key == k)
        {
            subset_node *b = (*sn)->right;
            int a = 1000000;
            if((*sn)->right == nullptr)
            {
                if((*sn)->left == nullptr)
                {
                    delete (*sn);
                    (*sn) = nullptr;
                    return true;
                }
                else
                {
                    subset_node *b = (*sn)->left;          ////////// left root of the tree
                    delete (*sn);
                    (*sn) = b;
                    /*while(b->left != nullptr || b->right != nullptr)
                    {
                        if(b->right != nullptr)
                        {
                            b = b->right;
                            a = min(b->key, a);
                        }
                        else b = b->left;
                    }
                    //cout << a << endl;
                    if(a == 1000000)
                    {
                        b = (*sn)->left;
                        delete (*sn);
                        (*sn) = b;
                    }
                    else
                    {
                        b = (*sn)->left;

                        while(b->right->key != a)
                        {
                            if(b->right != nullptr)
                            {
                                b = b->right;
                            }
                            else b = b->left;
                        }

                        subset_node *d = b->right->left;
                        delete b->right;
                        b->right = d;
                        (*sn)->key = a;
                    }*/
                }
            }
            else
            {
                subset_node *b = (*sn)->right;          ///////////////       right root of the tree
                while(b->left != nullptr)
                {
                    a = b->left->key;
                    b = b->left;
                }
                //cout << a << endl;
                if(a == 1000000)
                {
                    subset_node *r = (*sn)->right;
                    subset_node *l = (*sn)->left;
                    b = (*sn)->right;
                    delete (*sn);
                    (*sn) = b;
                    (*sn)->left = l;
                }
                else
                {
                    b = (*sn)->right;

                    while(b->left->key != a)
                    {
                        if(b->left != nullptr)
                        {
                            b = b->left;
                        }
                        else b = b->right;
                    }

                    subset_node *d = b->left->right;
                    delete b->left;
                    b->left = d;
                    (*sn)->key = a;
                }
            }

            return true;
        }
        else
        {
            subset_node *hard = (*sn);
            int y = 0;
            while(y == 0)
            {

                if((hard->right != nullptr && (hard->right)->key == k) || (hard->left != nullptr && (hard->left)->key == k))
                {
                    break;
                }
                if(k > hard->key)
                {
                    //cout << hard->key << endl;
                    hard = hard->right;
                }
                else
                {
                    //cout << hard->key << endl;
                    hard = hard->left;
                }

            }

            //cout << hard->left->key;

            if(hard->right != nullptr && hard->right->key == k)
            {
                int a = 1000000;
                //cout << "wrong";
                if((hard->right)->right == nullptr)
                {
                    if((hard->right)->left == nullptr)
                    {
                        delete (hard->right);
                        (hard->right) = nullptr;
                        return true;
                    }
                    else
                    {

                        subset_node *b = (hard->right)->left;          ////////// left root of the tree
                        delete (hard->right);
                        (hard->right) = b;
                    }
                }
                else
                {
                    subset_node *b = (hard->right)->right;          ///////////////       right root of the tree

                    while(b->left != nullptr)
                    {
                        a = b->left->key;
                        b = b->left;
                    }

                    //cout << a << endl;
                    if(a == 1000000)
                    {
                        subset_node *r = (hard->right)->right;
                        subset_node *l = (hard->right)->left;
                        b = (hard->right)->right;
                        delete (hard->right);
                        (hard->right) = b;
                        (hard->right)->left = l;
                    }
                    else
                    {
                        b = (hard->right)->right;

                        while(b->left->key != a)
                        {
                            if(b->left != nullptr)
                            {
                                b = b->left;
                            }
                            else b = b->right;
                        }

                        subset_node *d = b->left->right;
                        delete b->left;
                        b->left = d;
                        (hard->right)->key = a;
                    }
                }

                return true;
            }
            else if(hard->left != nullptr && hard->left->key == k)
            {
                //cout << "right";
                int a = 1000000;
                if((hard->left)->right == nullptr)
                {
                    if((hard->left)->left == nullptr)
                    {
                        delete (hard->left);
                        (hard->left) = nullptr;
                        return true;
                    }
                    else
                    {
                        subset_node *b = (hard->left)->left;          ////////// left root of the tree
                        delete (hard->left);
                        (hard->left) = b;
                    }
                }
                else
                {
                    subset_node *b = (hard->left)->right;          ///////////////       right root of the tree
                    while(b->left != nullptr)
                    {
                        a = b->left->key;
                        b = b->left;
                    }
                    //cout << a << endl;
                    if(a == 1000000)
                    {
                        subset_node *r = (hard->left)->right;
                        subset_node *l = (hard->left)->left;
                        b = (hard->left)->right;
                        delete (hard->left);
                        (hard->left) = b;
                        (hard->left)->left = l;
                    }
                    else
                    {
                        b = (hard->left)->right;

                        while(b->left->key != a)
                        {
                            if(b->left != nullptr)
                            {
                                b = b->left;
                            }
                            else b = b->right;
                        }

                        subset_node *d = b->left->right;
                        delete b->left;
                        b->left = d;
                        (hard->left)->key = a;
                    }
                }

                return true;
            }
        }
    }

}

int A[200000];
unsigned int z = 0;

void dfshelp(subset_node *c)
{
    if(!c) return;
    dfshelp(c->left);
    A[z] = c->key;
    z ++;
    //cout << c->key << " ";
    dfshelp(c->right);

}

int *DFS(subset_node *sn)
{
    int *mas = new int[size(sn)];
    z = 0;
    dfshelp(sn);
    int i = 0;
    for(i = 0; i < z; i ++) mas[i] = A[i];
    //cout << "help";


    return mas;

}
