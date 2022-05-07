//
// Created by Jason MacKeigan on 2022-05-07.
//
//URL
//https://leetcode.com/problems/path-sum/


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum);

bool hasPathSum(TreeNode* root, int targetSum, int current);

int main() {
    // first value is root for the input
    // then its left node, the right node
    //      node input can be null
}

bool hasPathSum(TreeNode* node, int targetSum, int current) {
    if (node == nullptr) {
        return false;
    }
    current += node->val;

    if (node->left == nullptr && node->right == nullptr) {
        return targetSum == current;
    }

    return hasPathSum(node->left, targetSum, current) || hasPathSum(node->right, targetSum, current);
}

bool hasPathSum(TreeNode *root, int targetSum) {
    return hasPathSum(root, targetSum, 0);
}