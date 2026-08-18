// /**
//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//  */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head;
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        // const int &nxt_val1 = list1->next->val;
        // const int &nxt_val2 = list2->next->val;
        const int &val1 = list1->val;
        const int &val2 = list2->val;
        if (val1 > val2)
        {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            head = list1;
            list1 = list1->next;
        }
        ListNode *now = head;

        while (list1 != nullptr && list2 != nullptr && now != nullptr)
        {
            if (val1 < val2)
            {
                now->next = list1;
                list1 = list1->next;
                now = now->next;
            }
            else
            {
                now->next = list2;
                list2 = list2->next;
                now = now->next;
            }
        }
        if(list1 == nullptr && list2 != nullptr)
        {
            while(list2 != nullptr)
            {
                now->next = list2;
                now = now->next ;
                list2 = list2 ->next;
            }
        }
        else if(list2 == nullptr && list1 != nullptr)
        {
            while(list1 != nullptr)
            {
                now->next = list1;
                now = now->next ;
                list1 = list1 ->next;
            }
        }
        return head;
    }
};