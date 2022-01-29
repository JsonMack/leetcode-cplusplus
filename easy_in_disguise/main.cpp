//
// Created by Jason MacK on 2022-01-16.
//
/**
 * The number of nodes in the tree is in the range [1, 2 * 10^4].
 *  1 <= Node.val <= 10^5
 *  1 <= low <= high <= 10^5
 *  All Node.val are unique.
 */
#include <exception>
#include <iostream>

using namespace std;

struct TreeNode;

/**
 * Return the sum of all values within the given inclusive range
 *
 * Example 1;
 *      Input:
 *      10 (root),
 *      5 (left child node of 10),
 *      15 (right child node of 10),
 *      3 (left of left child node),
 *      7 (right of left child node),
 *      null (left of right child node),
 *      18 (right of right child node)
 *
 * For inserting input
 *      First value is always root note
 *      Second value is always left node of root
 *      Third value is always right node of root
 *
 * Solution steps
 *       Search through binary tree
 */
int rangeSumBST(TreeNode* root, int low, int high);

int rangeSumBST(TreeNode* root, int low, int high, int *sum);

int testCase1();

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

int main() {
    testCase1();
}

int testCase1() {
    auto *root = new TreeNode(10);

    auto five = new TreeNode(5);

    auto fifteen = new TreeNode(15);

    auto three = new TreeNode(3);

    auto seven = new TreeNode(7);

    auto one = new TreeNode(1);

    auto six = new TreeNode(6);

    auto thirteen = new TreeNode(13);

    auto eighteen = new TreeNode(18);

    root->left = five;
    root->right = fifteen;
    five->left = three;
    five->right = seven;
    three->left = one;
    seven->left = six;
    fifteen->left = thirteen;
    fifteen->right = eighteen;

    int sum = rangeSumBST(root, 6, 10);

    assert(sum == 23);
}

int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;

    int *pSum = &sum;

    rangeSumBST(root, low, high, pSum);

    return sum;
}

int rangeSumBST(TreeNode* node, int low, int high, int *sum) {
    if (node == nullptr) {
        return 0;
    }
    int nodeValue = node->val;

    if (nodeValue >= low && nodeValue <= high) {
        *sum += nodeValue;
    }
    if (node->left != nullptr) {
        rangeSumBST(node->left, low, high, sum);
    }

    if (node->right != nullptr) {
        rangeSumBST(node->right, low, high, sum);
    }
    cout << *sum << endl;

    return *sum;
}