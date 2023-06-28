#include <iostream>

using namespace std;

struct ListNode 
{
    int data;
    ListNode *pre;
    ListNode *next;
};

ListNode *CreateList()
{
    ListNode *h = new ListNode;
    h->data = 0;
    h->pre = NULL;
    h->next = NULL;
    return h;
}

ListNode * Insert(ListNode *h, int data)
{
    if(!h)
    {
        return NULL;
    }

    ListNode *tmp = new ListNode;
    tmp->data = data;

    //cout << "33333333"<<endl;
    tmp->next = h;
    h->pre = tmp;
    h = tmp;
    return h;
    //cout << "2222222222"<<endl;
}

void Delete(ListNode *h, int data)
{
    if(!h)
    {
        return;
    }

    ListNode *tmp = h;
    while(tmp->next != NULL)
    {
        if (tmp->data == data)
        {
            ListNode *n = tmp;
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
            delete n;
            return;
        }
    }
}

ListNode* ListReverse(ListNode *h)
{
    if(!h)
    {
        return NULL;
    }

    ListNode *tmp = h->next;
    ListNode *n = h;
    while(tmp && tmp->next)
    {
        ListNode *tmp1 = tmp;
        tmp = tmp->next;
        tmp->pre = NULL;

        tmp1->next = n;
        n->pre = tmp1;
        tmp1->pre = NULL;
        n = tmp1;
    }

    tmp->next = n;
    n->pre = tmp;
    n = tmp;
    h->next = NULL;

    return n;
}

void Delete(ListNode *h)
{
    if(!h)
    {
        return;
    }

    ListNode *tmp = h;
    while(tmp)
    {
        ListNode *n = tmp;
        tmp = tmp->next;
        delete n;
    }
}

int main()
{
    ListNode *h = CreateList();

    h = Insert(h, 1);
    h = Insert(h, 2);
    h = Insert(h, 3);
    h = Insert(h, 4);
    h = Insert(h, 5);

    ListNode *tmp = h;
    while(tmp)
    {
        cout << tmp->data<< endl;
        tmp=tmp->next;
    }
    cout << "11111111111"<<endl;
    ListNode *n = ListReverse(h);
    ListNode *m = n;
    while(m)
    {
        cout << m->data<< endl;
        m=m->next;
    }

    Delete(n);
}
