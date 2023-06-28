#include <iostream>
using namespace std;


struct StackT {
    int cap;
    int *body;
    int top;
    void Init(int n);
    void Push(int val);
    int Pop();
};


void StackT::Init(int n)
{
    cap = n;
    body = new int[n];
    top = 0;
}


void StackT::Push(int n)
{
    if(top == (cap - 1))
    {
        return;
    }
    
    body[top] = n;
    top++;
}


int StackT::Pop()
{
    top--;
    return body[top];
}

struct List{
    int data;
    List *next;
};

List* CreateList(int n)
{
    List *h = new List;
    h->next = NULL;
    h->data = n;
    return h;
}

void Insert(List *h, int n)
{
    while(h->next)
    {
        h = h->next;
    }

    List *tmp = new List;
    tmp->data = n;
    h->next = tmp;
}

void Delete(List *h, int n)
{
    if(h && h->data ==n)
    {
        List *tmp = h;
        h = h->next;
        delete h;
        return;
    }

    while(h->next && h)
    {
        if(h->next->data == n)
        {
            List *tmp = h->next;
            h->next = h->next->next;
            delete tmp;
            return;
        }
    }
}

void Destroy(List *h)
{
    while(h)
    {
        List *tmp = h;
        h = h->next;
        delete tmp;
    }
}

bool IsPalinDrome(List *h, int n)
{
    if(!h)
    {
        return false;
    }

    StackT t;
    t.Init(n);

    List *slow = h;
    List *fast = h;
    bool push = false;
    while(slow)
    {
        if(fast->next != NULL && push == false)
        {
            t.Push(slow->data);
            slow = slow->next;
            if (!fast->next->next)
            {
                push = true;
            }
            else
            {
                fast = fast->next->next;
            }
        }
        else if(fast->next == NULL && push == false)
        {
            slow = slow->next;
            push = true;
        }
        else
        {
            if(t.Pop() != slow->data)
            {
                return false;
            }
            else
            {
                slow = slow->next;
            }
        }
    }
    return true;
}

int main()
{
    //int a[6] = {1,2,5,5,2,1};
    int a[2] = {1,2};
    List * h = CreateList(a[0]);

    for(int i=1;i < sizeof(a)/sizeof(int); i++)
    {
        Insert(h, a[i]);
    }
    
    List *tmp = h;
    while(tmp)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }

    bool b = IsPalinDrome(h, sizeof(a)/sizeof(int));
    if(b)
    {
        cout << "Is Palindrome" << endl;
    }else
    {
        cout << "Is Not Palindrome" << endl;
    }
    return 0;
}
