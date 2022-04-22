//
// Created by Jason MacKeigan on 2022-04-21.
//
#include <cmath>
#include <iostream>

using std::cout, std::endl;

// Definition of ListNode
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

void sum(ListNode*& root, ListNode* first, ListNode* second, bool remainder,
         const ListNode*& original_first, const ListNode*& original_second);

void print(ListNode* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->val << std::endl;
    print(node->next);
}

void first_test_case() {
    auto* first = new ListNode(2);

    first->next = new ListNode(4);
    first->next->next = new ListNode(3);

    auto* second = new ListNode(5);

    second->next = new ListNode(6);
    second->next->next = new ListNode(4);

    cout << "First linkedlist" << endl;
    print(first);

    cout << "Second linkedlist" << endl;
    print(second);

    ListNode* result = addTwoNumbers(first, second);

    cout << "Result(ing) linkedlist" << endl;
    print(result);
}

int main() {
    first_test_case();
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Initialize new linked list, to be returned as output
    ListNode* root = nullptr;

    const ListNode* original_first = l1;

    const ListNode* original_second = l2;

    // Initial function call, passing in the original linked list heads
    sum(root, l1, l2, false, original_first, original_second);

    // returning the output linked list
    return root;
}

void sum(ListNode*& root, ListNode* first, ListNode* second, bool remainder,
         const ListNode*& original_first,
         const ListNode*& original_second) {
    // Check if the first and second nodes are null, and if they are, we're at the end of the linked list
    if (first == nullptr && second == nullptr) {
        if (remainder) {
            root = new ListNode(1);
        }
        return;
    }
    // Get value of first if not nullptr, otherwise treat the value as zero
    int value_of_first = first == nullptr ? 0 : first->val;

    // same as above but for second list, otherwise treat the value as zero
    int value_of_second = second == nullptr ? 0 : second->val;

    // determine the sum of the first and second nodes and increase by 1 if there was previously
    // a remainder
    int sum_of_nodes = value_of_first + value_of_second + (remainder ? 1 : 0);

    // if we're not at the end of both, meaning either list still has a non-null node, continue to try and find the sum
    if (first != nullptr || second != nullptr) {
        sum(root, first == nullptr ? nullptr : first->next,
            second == nullptr ? nullptr : second->next, sum_of_nodes >= 10,
            original_first,
            original_second);
    }
    // To account for remainders, bubble over the extra 1
    int node_value = sum_of_nodes % 10;

    // Create new node, using node constructor to give node the proper assigned value
    auto new_node = new ListNode(node_value);

    // If root is null, then set root of new list to be the new node
    if (root == nullptr) {
        root = new_node;
    }
    else
    {
        new_node->next = root;
        root = new_node;
    }
}