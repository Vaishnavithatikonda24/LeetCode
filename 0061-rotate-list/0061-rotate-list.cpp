class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Handle edge cases

        // Step 1: Find the length of the list
        ListNode* temp = head;
        int n = 1; // Start with 1 because we're counting the head node
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Adjust k to prevent unnecessary rotations
        k = k % n;
        if (k == 0) return head; // No need to rotate if k is a multiple of n

        // Step 3: Find the new tail and new head
        ListNode* newTail = head;
        for (int i = 1; i < n - k; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        // Step 4: Break the list and perform the rotation
        newTail->next = nullptr;
        temp->next = head; // Connect the original tail to the head, making it circular

        return newHead;
    }
};
