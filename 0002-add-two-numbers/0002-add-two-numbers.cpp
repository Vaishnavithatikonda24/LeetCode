class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify list creation
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;  // Calculate carry for next step
            current->next = new ListNode(sum % 10); // Create new node for the digit
            current = current->next;
        }

        return dummyHead->next; // Return the actual head of the result list
    }
};
