//
// Created by Jason MacK on 2022-01-15.
//

struct ListNode;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

public:

    ListNode* removeElements(ListNode* head, int val) {
        return removeElements(head, val, head, nullptr);
    }

    ListNode* removeElements(ListNode* head, int val, ListNode* first, ListNode* previous) {
        if (head == nullptr) {
            return first;
        }
        if (head->val == val) {
            if (previous != nullptr) {
                previous->next = head->next;

                return removeElements(head->next, val, first, previous);
            }
            if (head == first) {
                first = head->next;
            }
            head = head->next;

            return removeElements(head, val, first, previous);
        }

        if (head->next == nullptr) {
            return first;
        }
        int nextValue = head->next->val;

        if (val == nextValue) {
            if (head->next->next == nullptr) {
                head->next = nullptr;
                return first;
            }
            head->next = head->next->next;
        }
        return removeElements(head->next, val, first, head);
    }
};

void testCase1();

void testCase2();

void testCase3();

int main() {
    testCase3();
}

void testCase1() {
    auto* first = new ListNode(1);

    auto second = new ListNode(2);

    auto third = new ListNode(6);

    auto fourth = new ListNode(3);

    auto fifth = new ListNode(4);

    auto sixth = new ListNode(5);

    auto seventh = new ListNode(6);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    Solution solution;

    solution.removeElements(first, 6, first, nullptr);
}

void testCase2() {
    auto* first = new ListNode(1);

    auto second = new ListNode(2);

    auto third = new ListNode(2);

    auto fourth = new ListNode(1);

    first->next = second;
    second->next = third;
    third->next = fourth;

    Solution solution;

    solution.removeElements(first, 2, first, nullptr);
}

void testCase3() {
    auto* first = new ListNode(5);

    auto second = new ListNode(4);

    auto third = new ListNode(3);

    auto fourth = new ListNode(2);

    auto fifth = new ListNode(1);

    auto sixth = new ListNode(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    Solution solution;

    solution.removeElements(first, 1, first, nullptr);
}
