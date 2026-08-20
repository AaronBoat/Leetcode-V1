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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode dummy(0,head);
        ListNode *s = &dummy;
        ListNode *f = &dummy;
        for (int i = 0; i < n + 1 ; i++)
        {
            f = f->next;
            // if (f == nullptr)
            // {
            //     return nullptr;
            // }
        }
        // f = f->next;
        while (f != nullptr)
        {
            f = f->next;
            s = s->next;
        } // s = n+1 个 倒数
        assert(s->next != nullptr);
        ListNode *s_n_n = s->next->next;
        delete (s->next);
        s->next = s_n_n;
        if(head == nullptr)
        {
            head = s;
        }
        return head;
    }
};