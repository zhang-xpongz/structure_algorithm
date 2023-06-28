#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};


ListNode *CreateList(int*a, int num)
{
    if(!a || num <=0)
    {
        return NULL;
    }

    ListNode *h = new ListNode;
    h->next = NULL;
    h->data = 0;
    ListNode *index = h;
    for(int i =0; i < num; i++)
    {
        ListNode *tmp = new ListNode;
        if(tmp)
        {
            tmp->data = a[i];
            tmp->next = NULL;
        }

        index->next = tmp;
        index = index->next;
    }

    return h;
}

ListNode *order(ListNode *a, ListNode *b)
{
    if(!a && b)
    {
        return b;
    }

    if(a && !b)
    {
        return a;
    }

    ListNode *c = new ListNode;
    c->data = 0;
    c->next = NULL;
    ListNode *tmp_a = a->next;
    ListNode *tmp_b = b->next;
    ListNode *tmp_c = c;
    while(tmp_a && tmp_b)
    {
        if(tmp_a->data < tmp_b->data)
        {
            tmp_c->next = tmp_a;
            tmp_a = tmp_a->next;
        }
        else
        {
            tmp_c->next = tmp_b;
            tmp_b = tmp_b->next;
        }
        tmp_c = tmp_c->next;
    }

    if(tmp_a)
    {
        while(tmp_a)
        {
            tmp_c->next = tmp_a;
            tmp_a = tmp_a->next;
            tmp_c = tmp_c->next;
        }
    }

    if(tmp_b)
    {
        while(tmp_b)
        {
            tmp_c->next = tmp_b;
            tmp_b = tmp_b->next;
            tmp_c = tmp_c->next;
        }
    }

    return c;
}

int main()
{
    int a[3] = {0,3,4};
    int b[4] = {1,2,4,5};

    ListNode *tmp1= CreateList(a, 3);
    ListNode *tmp2 = CreateList(b, 4);

    ListNode *tmp3 = order(tmp1, tmp2);

    while(tmp3)
    {
        cout<< tmp3->data<<endl;
        tmp3 = tmp3->next;
    }
}
