#include <iostream>

using namespace std;

struct subforwardlist {
     int data;
     subforwardlist* next;
};

bool init(subforwardlist **sfl)
{
    (*sfl) = nullptr;
    return true;
}

bool push_back(subforwardlist **sfl, int d)
{
    if((*sfl) == nullptr)
    {
        (*sfl) = new subforwardlist;
        (*sfl)->data = d;
        (*sfl)->next = nullptr;
    }
    else
    {
        subforwardlist *b = (*sfl);
        while(b->next != nullptr)
        {
            //cout << b->data << " ";
            b = b->next;
        }
        //cout << endl;
        subforwardlist *c = new subforwardlist;
        c->data = d;
        c->next = nullptr;
        b->next = c;
    }
    return true;
}

int pop_forward(subforwardlist **sfl)
{
    if((*sfl) == nullptr) return -1;
    subforwardlist *c = (*sfl)->next;
    int a = (*sfl)->data;
    delete (*sfl);
    (*sfl) = c;
    return a;
}

unsigned int size(subforwardlist  **sfl)
{
    subforwardlist *b = (*sfl);
    int i = 1;
    if((*sfl) == nullptr) return 0;
    else
    {
        while(b->next != nullptr)
        {
            i ++;
            b = b->next;
        }
        return i;
    }
}

bool push_forward(subforwardlist **sfl, int d)
{
    if((*sfl) == nullptr)
    {
        (*sfl) = new subforwardlist;
        (*sfl)->data = d;
        (*sfl)->next = nullptr;
    }
    else
    {
        /*subforwardlist *c = new subforwardlist;
        c->data = d;
        c->next = (*sfl);
        //delete[] (*sfl);
        (*sfl) = c;*/
        subforwardlist *b = (*sfl);
        (*sfl) = new subforwardlist;
        (*sfl)->next = b;
        (*sfl)->data = d;
        //delete b;
    }
    return true;
}


int pop_back(subforwardlist **sfl)
{
    subforwardlist *b = (*sfl);
    int a;
    if((*sfl) == nullptr) return 0;
    if((*sfl)->next != nullptr)
    {
        while((b->next)->next != nullptr)
        {
            //cout << b->data << " ";
            b = b->next;
        }
        //cout << endl;
        a = (b->next)->data;
        delete (b->next)->next;
        delete b->next;
        b->next = nullptr;

    }
    else
    {
        a = b->data;
        delete (*sfl);
        (*sfl) = nullptr;
    }
    return a;
}


bool push_where(subforwardlist **sfl, unsigned int where, int d)
{
    subforwardlist *c = (*sfl);
    int i = 0;
    if(where == 0)
    {
        subforwardlist *b = (*sfl);
        (*sfl) = new subforwardlist;
        (*sfl)->next = b;
        (*sfl)->data = d;
        return true;
    }
    for(i; i < where - 1; i ++)
    {
        //cout << i << " ";
        c = c->next;
    }
    //cout << endl;
    subforwardlist *e;
    subforwardlist *b = c;
    e = new subforwardlist;
    e->next = c->next;
    e->data = d;
    c->next = e;
    return true;

}

bool erase_where (subforwardlist **sfl, unsigned int where)
{
     if(where == 0 || (*sfl)->next == nullptr)
    {
        subforwardlist *c = (*sfl)->next;
        int a = (*sfl)->data;
        delete (*sfl);
        (*sfl) = c;
        return true;
    }
    else
    {
        int i = 0;
        subforwardlist *c = (*sfl);
        for(i; i < where - 1; i ++)
        {
            //cout << i << " ";
            c = c->next;
        }
        subforwardlist *b;
        b = (c->next)->next;
        delete c->next;
        c->next = b;
        return true;
    }
}


void clear(subforwardlist  **sfl)
{
    int n = size(sfl);
    int i = 0;
    for(i; i < n;  i ++)
    {
        pop_back(sfl);
    }
}
