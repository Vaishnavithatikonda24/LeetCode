class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases where the head might be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize both pointers to the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 1; i <= n + 1; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        slow->next = slow->next->next;
        
        // Return the head of the updated list (dummy->next points to the actual head)
        return dummy->next;
    }
};
