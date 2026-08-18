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
    // private:
    //     void swap_node(ListNode* a,ListNode* b)
    //     {
    //         if(a==nullptr || b==nullptr)
    //         {
    //             return;
    //         }
    //         ListNode* tem = b->next;
    //         a->next

    //     }
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *s = head;
        ListNode *pre_s = nullptr;
        ListNode *f = head;
        bool is_odd_nodes = true;
        while (s != nullptr && f != nullptr)
        {
            ListNode *tem_next = s->next;
            s->next = pre_s;
            s = tem_next;
            f = f->next;
            if (f == nullptr)
            {
                is_odd_nodes = false;
                break;
            }
        }
        ListNode *s2 = pre_s;
        if (s2 == nullptr)
        {
            return true;
        }
        while (s != nullptr)
        {
            if (s2->val != s->val)
            {
                return false;
            }
            s = s->next;
            s2 = s2->next;
        }
    }
};