class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy; // prev will always point to the node before the current pair
        ListNode* curr = head;  // curr will point to the first node in the current pair
        
        // Iterate through the list in pairs
        while (curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;
            
            // Swap the two nodes
            prev->next = second; // prev points to the second node
            first->next = second->next; // first node's next points to the node after the second node
            second->next = first; // second node's next points to the first node
            
            // Move prev and curr pointers to the next pair
            prev = first;
            curr = first->next;
        }
        
        return dummy->next; // Return the head of the new list (after dummy node)
    }
};
