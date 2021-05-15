//
// Created by shimeng on 2021/4/21.
//

#ifndef LEETCODE_COMPETITION_TREENODE_H
#define LEETCODE_COMPETITION_TREENODE_H

#include "common.h"

class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    int val;

//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//
//    // Encodes a tree to a single string.
//    static string serialize(TreeNode* root) {
//
//    }
//
//    // Decodes your encoded data to tree.
//    static TreeNode* deserialize(string data) {
//
//    }
//
//    static TreeNode* buildTree(const vector<int> &nodes) {
//        if (nodes.empty()) {
//            return nullptr;
//        }
//        queue<TreeNode*> record;
//        auto *root = new TreeNode(nodes[0]);
//        record.push(root);
//        for (int i = 1; i < record.size(); ++i) {
//
//        }
//        for (const int &item : nodes) {
//
//        }
//    }
};

#endif //LEETCODE_COMPETITION_TREENODE_H
