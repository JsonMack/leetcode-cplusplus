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

// [1, 2]


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            if (n == 1) {
                return nullptr;
            }
            return head;
        }
        ListNode* current = head;

        int length = 0;

        while (current != nullptr) {
            length++;
            current = current->next;
        }
        int index = 0;

        current = head;

        int target_index = length - n - 1;

        if (n == length) {
            head = head->next;

            return head;
        }
        while (index++ < target_index) {
            current = current->next;
        }
        ListNode* next = current->next;

        ListNode* after_next = next->next;

        if (after_next != nullptr) {
            current->next = after_next;
        } else {
            current->next = nullptr;
        }
        return head;
    }
};

int main() {

}

