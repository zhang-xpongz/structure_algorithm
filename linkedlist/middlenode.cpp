#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

ListNode * Middle(ListNode *h)
{
    ListNode *slow,*fast;
    slow = fast = h;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{

}
