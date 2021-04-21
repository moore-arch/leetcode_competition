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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode* buildTree(const vector<int> &record) {

    }
};

#endif //LEETCODE_COMPETITION_TREENODE_H
