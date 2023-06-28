#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode *next;
};

bool judgeLoop(ListNode *h)
{
    ListNode *slow, *fast;
    slow = fast = h;
    while(slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }

    return false;
}


ListNode *LoopStart(ListNode *h)
{
    ListNode *slow, *fast;
    slow = fast = h;

    while(slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if(slow==NULL || fast->next==NULL)
        return NULL;

    ListNode *begin = h;

    while(begin != slow)
    {
        begin = begin->next;
        slow = slow->next;
    }

    return begin;
}

int LoopLength(ListNode *h)
{
    ListNode *begin = LoopStart(h);

    ListNode *tmp = begin;
    int len = 0;
    while(tmp->next !=begin)
    {
        tmp = tmp->next;
        len++;
    }
    return len;
}

int ListLength(ListNode *h)
{
    int len1 = LoopLength(h);

    ListNode *begin = LoopStart(h);
    ListNode *tmp = h;
    int len2 = 0;
    while(begin != tmp->next)
    {
        tmp = tmp->next;
        len2++;
    }

    return (len1 + len2);
}

int main()
{

}
