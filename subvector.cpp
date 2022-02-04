#include <iostream>

using namespace std;

struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector *qv)
{
    qv->capacity = 0;
    qv->top = 0;
    qv->mas = NULL;
    return true;
}

bool push_back(subvector *qv, int d)
{
    if(qv->top < qv->capacity)
    {
        qv->mas[qv->top] = d;
    }
    else
    {
        if(qv->capacity != 0) (qv->capacity) *= 2;
        else (qv->capacity ++);
        int *a = new int[qv->capacity];
        for(int i = 0; i < qv->top; i ++)
            a[i] = qv->mas[i];
        a[qv->top] = d;
        delete[] qv->mas;
        qv->mas = a;
    }
    (qv->top) ++;
    return true;
}

int pop_back(subvector *qv)
{
    if(qv->top > 0)
    {
         int b = qv->mas[(qv->top) - 1];
         (qv->top) --;
         return b;
    }
    else return 0;
}


bool resize(subvector *qv, unsigned int new_capacity)
{
    int *a = new int[new_capacity];
    if(new_capacity < qv->top) qv->top = new_capacity;
    for(int i = 0; i < qv->top; i ++)
        a[i] = qv->mas[i];
    delete[] qv->mas;
    qv->mas = a;
    qv->capacity = new_capacity;
    return true;
}


void shrink_to_fit(subvector *qv)
{
    qv->capacity = qv->top;
}


void clear(subvector *qv)
{
    qv->top = 0;
}

void destructor(subvector *qv)
{
    delete[] qv->mas;
    init(qv);
}
