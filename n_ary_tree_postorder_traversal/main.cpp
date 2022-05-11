//
// Created by Jason MacKeigan on 2022-05-08.
//
#include <vector>
#include <iostream>

using std::vector, std::cout, std::endl;

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
    vector<int> postorder(Node* root) {
        vector<int> ordered;

        traverse(root, ordered);

        return ordered;
    }

    void traverse(Node* node, vector<int>& ordered) {
        if (node == nullptr) {
            return;
        }
        for (auto child : node->children) {
            traverse(child, ordered);
        }
        ordered.push_back(node->val);
    }
};

int main() {
    Node* root = new Node(1);

    root->children = vector({ new Node(3), new Node(2), new Node(4) });
    root->children[0]->children = vector({ new Node(5), new Node(6) });

    Solution solution;

    vector<int> ordered = solution.postorder(root);

    for (auto val : ordered) {
        std::cout << val << std::endl;
    }
}