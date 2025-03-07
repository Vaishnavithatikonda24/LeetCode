class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Move `prev` to the node before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // `start` is the first node of the sublist to be reversed
        ListNode* start = prev->next;
        ListNode* then = start->next;
        
        // Reverse the sublist using a standard in-place reversal
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }
        
        return dummy.next;
    }
};