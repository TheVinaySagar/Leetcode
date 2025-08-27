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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr; 
        while(curr != nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        ListNode *first = head;
        ListNode *second = prev;

        while(second != nullptr)
        {
            ListNode *temp1= first->next; 
            ListNode *temp2 = second->next;
            second->next = temp1;
            first->next = second;

            first = temp1;
            second = temp2;
        }
    }
};