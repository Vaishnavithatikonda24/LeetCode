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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;  // Edge case: Empty list

        ListNode* dummy = new ListNode(0, head);  // Dummy node to simplify edge cases
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all duplicate nodes
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;  // Remove all duplicates
            } else {
                prev = prev->next;  // Move prev only if no duplicates
            }
            head = head->next;
        }

        return dummy->next;
    }
};
