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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode *temp = 


        ListNode *temp = new ListNode(-1);
        ListNode *list1 = l1;
        ListNode *list2 = l2;
        ListNode *dummy = temp;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                dummy->next = list1;
                dummy = dummy->next;
                list1 = list1->next;
            }
            else
            {
                dummy->next = list2;
                dummy = dummy->next;
                list2 = list2->next;
            }
        }

        if(list2 != nullptr)
        {
            dummy->next = list2;
        }

        if(list1 != nullptr)
        {
            dummy->next = list1;
        }


        return temp->next;
    }
};