//
// Created by Jason MacK on 2022-01-29.
//

  struct ListNode {
    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
// Example 1
//    Input: head = [1,2,3,4,5], k = 2
//    Output: [1,4,3,2,5]

// Example 2
//    Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
//    Output: [7,9,6,6,8,7,3,0,9,5]


public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head->next == nullptr) {
            return head;
        }
        // keep track of original head
        ListNode* original_head = head;

        // find length of linked list
        int length = 0;

        ListNode* current = original_head;

        ListNode* first = nullptr;

        // while we try to find the first node and the length
        while (current != nullptr) {
            if (length++ == k - 1) {
                first = current;
            }
            current = current->next;
        }
        // at this point we have the length of the linked list
        // navigate to length - k - 1 node
        ListNode* target = original_head;

        int current_index = 0;

        while (target != nullptr) {
            if (current_index++ == length - k) {
                break;
            }
            target = target->next;
        }
        int first_value = first->val;

        first->val = target->val;
        target->val = first_value;

        return head;
    }
};

int main() {

}
