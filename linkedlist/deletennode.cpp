#include <iostream>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
};

void DleteNode(ListNode *h, int n)
{
    ListNode *ptr1, *ptr2;
    ptr1 = ptr2 = h;

    int cnt = 0;
    while(ptr1)
    {
        ptr1 = ptr1->next;
        if(cnt < n)
        {
            cnt++;
        }else{
            ptr2 = ptr2->next;
        }
    }

    ListNode *tmp = ptr2->next;
    ptr2->next = ptr2->next->next;
    delete tmp;
}

int main()
{

}
