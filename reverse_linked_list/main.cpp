//
// Created by Jason MacK on 2022-01-16.
// "OH YEAH" - Kool-Aid Guy
// Gideon: hello! Im finally here!
#include <iostream>

/**
 * #206
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 * Example 1:
 *      FROM:
 *          1, 2, 3, 4, 5
 *      TO:
 *          5, 4, 3, 2, 1
 *
 * Example 2:
 *      FROM:
 *          1, 2
 *      TO:
 *          2, 1
 *
 *
 *  Constraints:
 *      The number of nodes in the list is the range [0, 5000].
 *      Node value range: -5000 <= Node.val <= 5000
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findTail(ListNode* head) {
    ListNode* current = head;

    ListNode* previous = nullptr;

    while (current != nullptr) {
        previous = current;
        current = current->next;
    }
    return previous;
}

// [ 1, 2, 3, 4, 5 ]
// current is 1
ListNode* reverseList(ListNode* head, ListNode* originalTail, ListNode* currentTail) {
    if (currentTail == originalTail) {
        return originalTail;
    }
    ListNode* newTail = findTail(head);

    currentTail->next = newTail;

    newTail->next = nullptr;

    return reverseList(head, originalTail, newTail);
}

// reverse(current, previous)
ListNode* reverseList(ListNode* head) {
    ListNode* originalTail = findTail(head);

    return reverseList(head, originalTail, originalTail);
}

ostream& operator<<(ostream& output, ListNode* node) {
    ListNode* current = node;

    while (current != nullptr) {
        output << current->val << ", ";
    }
    output << endl;

    return output;
}
// Driver code
int main() {
    auto* first = new ListNode(1);

    auto* second = new ListNode(2);

    auto* third = new ListNode(3);

    auto* fourth = new ListNode(4);

    auto* fifth = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    ListNode* newHead = reverseList(first);

    cout << newHead << endl;
}

/*
 *  ListNode* reverseList(ListNode* head) {
        return reverseList(head, head->next);
    }

    ListNode* reverseList(ListNode *current, ListNode *next) {
        cout << "Current Val: " << current->val << endl;
        cout << "Next Val: " << next->val << endl;
        // check if you're one step from the end
        if (next->next == nullptr) {
            cout << "Next next is null!!" << endl;
            cout << "Current Next value is pointing to " << current->next->val << endl;
            // Re-orient the next pointer to point at current
            next->next = current;

            return next;
        } else {
            // keeping track of current, and next
            // setting next->next to temp, so looking two down (since ideally we know it is not null)
            ListNode *temp = next->next;
            cout << "Temp value is pointing to " << temp->val << endl;
            // assigning next->next to current so it points backwards
            next->next = current;

            return reverseList(next, temp);
        }
    }
 *
 * */