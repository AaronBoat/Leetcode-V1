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
#include<stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> val_stack;
        while(head != nullptr)
        {
            if(head->val == val_stack.top())
            {
                val_stack.pop();

            }
            else{
                val_stack.push(head->val);
            }
            head = head->next;
        }
        return val_stack.empty();
    }
};