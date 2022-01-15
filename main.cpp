#include <iostream>
#include <vector>
#include "MoveZeroesSolution.h"
#include <queue>

using namespace std;

class Solution;

struct ListNode;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

ListNode* alex(ListNode* list1, ListNode* list2);

ListNode* jason(ListNode* list1, ListNode* list2);

ListNode* gideon(ListNode* list1, ListNode* list2);

ListNode* ryan(ListNode* list1, ListNode* list2);

void drain(ListNode* from, ListNode* to);

struct ListNode {

    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {

    }

    ListNode(int x) : val(x), next(nullptr) {

    }

    ListNode(int x, ListNode *next) : val(x), next(next) {

    }

};

int main() {
    auto *list1(new ListNode(1));

    list1->next = new ListNode(2);

    list1->next->next = new ListNode(4);

    auto *list2(new ListNode(1));

    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *result = jason(list1, list2);

    queue<int> values = queue<int>({1, 1, 2, 3, 4, 4});

    while (result != nullptr) {
        int expected = values.front();

        if (result->val != expected) {
            throw invalid_argument("Expected " + to_string(expected) + " but received " + to_string(result->val) + ".");
        }
        cout << "Match: " << expected << endl;

        values.pop();

        result = result->next;
    }
    return 0;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Compare both of the lists
    // If both nodes are the same, add the value at that node (from the first) to the merged list
    // If both nodes are different, compare for the min and add the min to the merged lis
    /* Comparing
     * if (list1.val > list2.val){};
     *
     * Set the new head
     *
     */

    // Check to see which of the list is null
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }


    // [ 1, 2, 4 ]
    // [ 1, 3, 4 ]
    // Compare the values that are in each of the list by using a pointer
    if (list1->val < list2->val)
    {
        // Set the head to list that is greater
        list1->next = mergeTwoLists(list1->next, list2);

        // Return the head of the list we pulled from
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);

        return list2;
    }
}

ListNode *alex(ListNode *list1, ListNode *list2) {

    return nullptr;
}

/**
 * Determine which list we're draining from
 * Head is 1 and 1
 *
 * 1. [ 1, 2, 4 ]
 *    [ 1, 3, 4 ]
 *
 * Head of list2 is inserted between head and head.next
 * 2. [ 1, 1, 2, 4 ]
 *    [ 3, 4 ]
 *
 * 3. [  ]
 *
 *
 * @param list1
 * @param list2
 * @return
 */
// Determine which list we're draining from
//      If list1.val > list2.val
//          list1 is what we're draining from
//          list2 is what we're draining into
//      Else
//          list2 is what we're draining from
//          list 1 is what we're draining into
//
//
ListNode *jason(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr || list2 == nullptr) {
        return list1 == nullptr ? list2 : list1;
    }
    ListNode *drainFrom = list1->val > list2->val ? list1 : list2;

    ListNode *drainTo = list1 == drainFrom ? list2 : list1;

    drain(drainFrom, drainTo);

    return drainTo;
}

void drain(ListNode *from, ListNode *to) {
    if (from == nullptr) {
        return;
    }
    ListNode *toNext = to->next;

    if (toNext == nullptr) {
        to->next = from;
        return;
    }
    if (from->val >= to->val && from->val <= toNext->val) {
        ListNode *fromNext = from->next;

        to->next = from;
        from->next = toNext;

        drain(fromNext, toNext);
    } else {
        drain(from, toNext);
    }
}

ListNode* HEAD;
ListNode *gideon(ListNode *list1, ListNode *list2) {
    // CHECKING FOR NULLS
    // if list1 is null and list2 is null, return empty list
    // if list1 is null and list2 is NOT null, return list2
    // Vice versa, list2 is null and list1 is NOT null, return list1

    // FINDING LOWEST VALUE TO DETERMINE LIST HEAD
    // if list1.val < list2.val, list1 = HEAD
    // Vice versa, list2 = HEAD

    // TRAVERSING THE TREE, TAKIN NAMES
    // if list1.head = list2.head, set list1.next = list2.head
    // Have cascading if statements?
    // 1. if list2.val == list1.val, set list1.next to list2
    // 2. if list2.val >= list1.val || list


        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        // if list1 is less than list2, list1 is HEAD
        if (list1->val < list2->val) {
            HEAD = list1;
            list1 = list1->next;
        } else if (list2->val < list1->val) {
            HEAD = list2;
            list2 = list2->next;
        }

        cout << "list1 " << list1->val << endl;
        cout << "list2 " << list2->val << endl;
        list1 = list1->next;
        list2 = list2->next;
        cout << "list1 " << list1->val << endl;
        cout << "list2 " << list2->val << endl;
        return HEAD;

}

ListNode *ryan(ListNode *list1, ListNode *list2) {

    // if a list is null, return other list, call it a day
    if(!list1->next || !list2->next) {
        if (!list1->next) { // use ternary here instead
            return list2;
        }
        if (!list2->next) {
            return list1;
        }
    }

    // determine which list has a smaller head (bias towards list1)
    // if list1's head is smaller, set outputList to be list1, same for list2. this will be the returned list
    if(list1->next <= list2->next){
        ListNode *outputList = list1;
    }
    else {
        ListNode *outputList = list2;
    }
    // take bigger head and insert after smaller head in outputList
        // Before doing so, find drained list's head's nextPtr and store in var
        // also find the outputList's head's nextPtr and assign this to var (assign to incoming node).


    return nullptr;
}
