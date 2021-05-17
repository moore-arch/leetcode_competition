//
// Created by shimeng on 2021/5/17.
//

#include "TreeNode.h"
#include "common.h"

using namespace std;
/**
 * dfs查找返回结果，第一个是父节点，第二个是深度
 */
using Result = pair<TreeNode*, int>;

/**
 * 遍历整个树，对于x和y均找到对应的父节点和深度，然后对比
 * @param root
 * @param parent
 * @param target
 * @param depth
 * @return
 */
Result dfs(TreeNode *root, TreeNode *parent, int target, int depth) {
    if (!root) {
        return {nullptr, 0};
    } else if (root->val == target) {
        return {parent, depth};
    }

    Result left = dfs(root->left, root, target, depth + 1);
    if (left.first) {
        return left;
    }
    return dfs(root->right, root, target, depth + 1);
}

bool isCousins(TreeNode* root, int x, int y) {
    Result xResult = dfs(root, nullptr, x, 0);
    Result yResult = dfs(root, nullptr, y, 0);

    // 可以去除冗余判断，因为xResult和yResult默认值相同，如果有一个找到，另一个未找到，则直接判断父节点不相同且节点深度相同也能得出结论
    return xResult.first != yResult.first && xResult.second == yResult.second;
    // return xResult.first && yResult.first && xResult.first != yResult.first && xResult.second == yResult.second;
}

int main()
{
    return 0;
}
