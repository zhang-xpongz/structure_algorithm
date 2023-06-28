#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

bool find(ListNode *head, int val)
{
    if(!head)
    {
        return false;
    }
    
    ListNode *tmp = head;
    for(; tmp!=NULL; )
    {
        if(tmp->val == val)
        {
            return true;
        }

        if(tmp->next == NULL)
        {
            break;
        }

        tmp=tmp->next;
    }

    return false;
}

void insert(ListNode *head, int val)
{
    if(!head)
    {
        return;
    }

    ListNode *tmp = head;
    for( ;tmp != NULL && tmp->next !=NULL; tmp=tmp->next)
    {

    }

    ListNode *newNode = new ListNode;
    if(newNode)
    {
        newNode->val = val;
    }

    tmp->next = newNode;
}

void del(ListNode *head, int val)
{
    if(!head)
    {
        return;
    }

    if(head->val == val)
    {
        ListNode *tmpHead = head;
        head = head->next;
        delete tmpHead;
        return;
    }

    ListNode *tmp = head;
    for(; tmp!=NULL && tmp->next!=NULL;tmp=tmp->next)
    {
        if(tmp->next->val == val)
        {
            ListNode *del = tmp->next;
            tmp->next = tmp->next->next;
            delete del;
            return;
        }
    }
}

ListNode* reverse(ListNode *h)
{
    if(!h)
        return NULL;

    ListNode *tmp = h->next;
    ListNode *head = h;
    while(tmp)
    {
        ListNode *n = tmp;
        tmp = tmp->next;
        n->next = head;
        head = n;
    }
    h->next = NULL;
    return head;
}

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    int len = sizeof(a)/sizeof(int);
    //cout << len << std::endl;

    ListNode *head = NULL;
    ListNode *tail = NULL;
    for(int i=0; i < len; i++)
    {
        ListNode *tmp = new ListNode;
        if(tmp)
        {
            tmp->val = a[i];
            tmp->next = NULL;
        }

        if(!head)
        {
            head = tmp;
        }

        if(!tail)
        {
            tail = tmp;
        }

        tail->next = tmp;
        tail = tmp;
        //cout << i << endl;
    }
   

    insert(head, 10);

    insert(head, 11);
    insert(head, 12);
    del(head, 4);

    //bool b = find(head, 3);
    //bool c = find(head, 14);
    //cout << b << endl;
    //cout << c << endl;

    ListNode *tmp = head;
    for (; tmp != NULL; tmp=tmp->next)
    {
        cout << tmp->val << endl;
    }
    cout << "------------"<<endl;    
    ListNode *rev = reverse(head);

    tmp = rev;
    for (; tmp != NULL; tmp=tmp->next)
    {
        cout << tmp->val << endl;
    }

    //cout << tmp->val << endl;
    return 0;
}
