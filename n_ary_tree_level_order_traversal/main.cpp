//
// Created by Jason MacKeigan on 2022-05-08.
//
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }
        vector<int> current;

        result.push_back({ root->val });

        levelOrder(root, current, result);

        return result;
    }

    void levelOrder(Node* node, vector<int>& current, vector<vector<int>>& result) {
        if (node == nullptr) {
            result.push_back(current);
            return;
        }
        current.push_back(node->val);

        if (node->children.empty()) {
            return;
        }
        vector<int> level;

        for (auto child : node->children) {
            level.push_back(child->val);
        }
        result.push_back(level);

        for (auto child : node->children) {
            levelOrder(child, result);
        }
    }
};

int main() {

}