/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* s_second = head ;
        bool is_s_meet_f = false;
        while(s != nullptr && f != nullptr)
        {
            s = s->next;
            f=f->next;
            if(f==nullptr)
            {
                return nullptr;
            }
            f=f->next;

            if(s == f)
            {
                is_s_meet_f =true;
            }
            if(is_s_meet_f)
            {
                s_second = s_second->next;
            }
            if(s == s_second)
            {
                return s;
            }
        }
        return nullptr;
    }
};