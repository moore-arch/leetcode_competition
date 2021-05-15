//
// Created by shimeng on 2021/5/15.
//

#ifndef LEETCODE_COMPETITION_LISTNODE_H
#define LEETCODE_COMPETITION_LISTNODE_H

class ListNode {
    int val;
    ListNode *left;
    ListNode *right;

    ListNode(int value): val(value), left(nullptr), right(nullptr) {}
};

#endif //LEETCODE_COMPETITION_LISTNODE_H
