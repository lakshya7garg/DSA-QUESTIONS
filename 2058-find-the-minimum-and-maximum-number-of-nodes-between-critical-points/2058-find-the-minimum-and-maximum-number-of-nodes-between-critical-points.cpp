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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (!head || !head->next || !head->next->next)
            return ans;

        int pos = 1;
        int prevVal = head->val;
        ListNode* curr = head->next;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next) {
            int nextVal = curr->next->val;

            // Check if current node is a critical point
            if ((curr->val > prevVal && curr->val > nextVal) ||
                (curr->val < prevVal && curr->val < nextVal)) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prevVal = curr->val;
            curr = curr->next;
            pos++;
        }

        // Need at least two critical points
        if (first == last)
            return ans;

        ans[0] = minDist;
        ans[1] = last - first;

        return ans;
    }
};