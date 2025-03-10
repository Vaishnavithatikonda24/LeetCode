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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode(0);  // Head of list < x
        ListNode* largeDummy = new ListNode(0);  // Head of list >= x
        ListNode* small = smallDummy, *large = largeDummy;
        
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        
        large->next = nullptr;  // Terminate large list
        small->next = largeDummy->next;  // Connect small list to large list
        
        return smallDummy->next;
    }
};
