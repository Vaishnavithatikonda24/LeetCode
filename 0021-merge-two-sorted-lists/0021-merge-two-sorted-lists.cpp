class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy; // Pointer to build the result list
        
        // Iterate through both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;  // Add the smaller node to the result list
                list1 = list1->next;    // Move the pointer forward in list1
            } else {
                current->next = list2;  // Add the smaller node to the result list
                list2 = list2->next;    // Move the pointer forward in list2
            }
            current = current->next; // Move the current pointer forward
        }
        
        // If any list still has remaining nodes, append them to the result list
        if (list1 != nullptr) {
            current->next = list1;
        } else if (list2 != nullptr) {
            current->next = list2;
        }
        
        // Return the merged list starting from dummy.next (skip the dummy node)
        return dummy->next;
    }
};
