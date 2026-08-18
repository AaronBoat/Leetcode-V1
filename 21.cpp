/**
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
#define val1 list1->val
#define val2 list2->val
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
        // int &val1 = list1->val;
        // int &val2 = list2->val;
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
                /*
                    cout<<"Now choose val1 cause val1: "<<val1<<" val2: "<<val2<<"\n";
                */
                now->next = list1;
                list1 = list1->next;
                now = now->next;
            }
            else
            {
                /*
                    cout<<"Now choose val2 cause val1: "<<val1<<" val2: "<<val2<<"\n";
                */
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