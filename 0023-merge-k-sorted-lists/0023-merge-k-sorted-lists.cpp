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

        priority_queue< pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>> >
            pq;


        // O(nlog(k))
        for (int i = 0; i < n; i++) {
            if (lists[i] != nullptr)
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // O(n*k)(number of node inside the prio que) x log(k)(inside push, pop, top operation)
        while (!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();

            dummy->next = node;

            if (node->next != nullptr)
                pq.push({node->next->val, node->next});

            dummy = dummy->next;
        }

        return temp->next;

        // So the Overall time complexity is O(n*k)*O(log(k)) + k*log(k) ~ O(n*k*log(k))
        // Space Complexity is O(k)
    }
};