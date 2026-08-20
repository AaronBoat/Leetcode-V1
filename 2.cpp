/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        int val = 0;
        int c = 0;

        ListNode dummy(0);
        ListNode *node_now = &dummy;
        ListNode *node_next;

        while (l1 != nullptr && l2 != nullptr)
        {
            val = l1->val + l2->val + c;
            c = val / 10;
            val = val % 10;
            node_next = new ListNode(val);
            node_now->next = node_next;
            node_now = node_next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            if (c == 0)
            {
                node_now->next = l1;

                break;
            }
            else
            {
                val = l1->val + c;
                c = val / 10;
                val = val % 10;
                node_next = new ListNode(val);
                node_now->next = node_next;
                node_now = node_next;
                l1 = l1->next;
            }
        }
        while (l2 != nullptr)
        {
            if (c == 0)
            {
                node_now->next = l2;
                break;
            }

            else
            {

                val = l2->val + c;
                c = val / 10;
                val = val % 10;
                node_next = new ListNode(val);
                node_now->next = node_next;
                node_now = node_next;
                l2 = l2->next;
            }
        }
        if (c >= 1 && c <= 9)
        {
            node_next = new ListNode(c);
            node_now->next = node_next;
            node_now = node_next;
        }
        return dummy.next;
    };
};