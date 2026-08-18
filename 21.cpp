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
        const int &nxt_val1 = list1->next->val;
        const int &nxt_val2 = list2->next->val;
        if(list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
        head = list1->val > list2->val ? list2 : list1;
        ListNode *now = head;

        while (list1 != nullptr && list2 != nullptr &&now != nullptr)
        {
            if (nxt_val1 > nxt_val1)
            {
                now->next = list1->next;
                list1 = list1->next;
                now = now->next;
            }
            else
            {
                now->next = list2->next;
                list2 = list2->next;
                now = now->next;
            }

        }
        return head;
    }
};