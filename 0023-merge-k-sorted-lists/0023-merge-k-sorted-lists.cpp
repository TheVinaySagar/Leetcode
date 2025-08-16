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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];

        ListNode *l1Dum = lists[0];
        ListNode *l1 = l1Dum;
        
        for(int i=1;i<n;i++)
        {
            ListNode *temp = new ListNode(-1);
            ListNode *dummy = temp;
            ListNode *l2 = lists[i];
            
            while(l1 != nullptr && l2 != nullptr)
            {
                if(l1->val < l2->val)
                {
                    dummy->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    dummy->next = l2;
                    l2 = l2->next;
                }
                dummy = dummy->next;
            }

            if(l1 != nullptr)
            {
                dummy->next = l1;
            }
            if(l2 != nullptr)
            {
                dummy->next = l2;
            }

            l1Dum = temp->next;
            l1 = l1Dum;
        }

        return l1Dum;
    }
};