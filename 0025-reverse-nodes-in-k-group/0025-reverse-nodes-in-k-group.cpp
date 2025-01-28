class Solution {
public:
    // Function to reverse a portion of the list from start to end
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next;
        
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  // No need to reverse if list is empty or k == 1
        
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy; // This will be the end of the previous group
        
        ListNode* groupStart = head;
        while (groupStart) {
            ListNode* groupEnd = groupStart;
            
            // Move groupEnd to the k-th node or stop if there aren't enough nodes left
            for (int i = 1; i < k && groupEnd; ++i) {
                groupEnd = groupEnd->next;
            }
            
            if (!groupEnd) break;  // Not enough nodes left to reverse
            
            ListNode* nextGroupStart = groupEnd->next;  // Save the start of the next group
            // Reverse the current group
            ListNode* newGroupStart = reverse(groupStart, groupEnd->next);
            
            // Connect the previous part with the new reversed group
            prevGroupEnd->next = newGroupStart;
            groupStart->next = nextGroupStart;  // Connect the old head of the group to the next part
            
            // Move prevGroupEnd and groupStart pointers for the next iteration
            prevGroupEnd = groupStart;
            groupStart = nextGroupStart;
        }
        
        return dummy->next;
    }
};
