#include "common.h"
#include "TreeNode.h"

using namespace std;

int pre = 0;
int res = INT32_MAX;

void dfs(TreeNode *root) {
	if (!root) {
		return ;
	}
	dfs(root->left);
	if (pre == -1) {
		pre = root->val;
	} else {
		res = min(res, abs(pre - root->val));
		pre = root->val;
	}
	dfs(root->right);
}

/**
 * @brief 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 
 * @param root 根结点
 * @return int 
 */
int minDiffInBST(TreeNode* root) {
	dfs(root);
	return res;
}

int main()
{
	return 0;
}