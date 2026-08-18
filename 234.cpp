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
        if(head == nullptr)
        {
            return true;
        }
        stack<int> val_stack;
        val_stack.push(head->val);
        int count_node = 1;
        int add_single_index = -1;
        head = head->next;
        while(head != nullptr)
        {
            if(head->val == val_stack.top())
            {
                val_stack.pop();

            }
            else{
                val_stack.push(head->val);
                add_single_index = count_node;
            }
            head = head->next;
            count_node ++;
        }
        if(val_stack.empty())
        {
            return true;
        }
        else{
            if(add_single_index == count_node / 2 && count_node % 2 ==1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};