class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        ListNode *s = head;
        ListNode *f = head;
        ListNode *pre_s = nullptr;

        // 1. 快慢指针：f 走两步，s 走一步并同时反转前半部分
        while (f != nullptr && f->next != nullptr) {
            f = f->next->next; // 先让快指针安全走两步

            // s 反转一步
            ListNode *tem_next = s->next;
            s->next = pre_s;
            pre_s = s;
            s = tem_next;
        }

        // 2. 奇数节点处理：若 f != nullptr，说明链表长度为奇数，s 停在正中间节点，需要跳过
        if (f != nullptr) {
            s = s->next;
        }

        // 3. 比较前半部分（已反转，头节点为 pre_s）和后半部分（头节点为 s）
        while (s != nullptr) {
            if (pre_s->val != s->val) {
                return false;
            }
            pre_s = pre_s->next;
            s = s->next;
        }

        return true;
    }
};