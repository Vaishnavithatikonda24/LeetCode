#include <queue>
#include <vector>
using namespace std;

// Assuming the ListNode is already defined in the included header file, so no need to redefine it.
// We can directly use it from the header file

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a min-heap to store the elements with their list index
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Initialize the min-heap with the first element of each list
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        ListNode *dummy = new ListNode(0); // dummy node to simplify the merge process
        ListNode *current = dummy;

        // Extract the minimum node from the heap and process the next node from that list
        while (!minHeap.empty()) {
            ListNode *node = minHeap.top();
            minHeap.pop();

            current->next = node; // Link the node to the merged list
            current = current->next; // Move the current pointer forward

            if (node->next != nullptr) {
                minHeap.push(node->next); // Push the next element from the same list
            }
        }

        return dummy->next; // Return the merged list (skip the dummy node)
    }
};
