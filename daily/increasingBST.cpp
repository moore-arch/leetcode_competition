#include "common.h"
#include "TreeNode.h"

using namespace std;

// method1, 中序遍历，保存结果并重建二叉树

// method2, 改变指向

TreeNode *preNode;

void inorder(TreeNode *root) {
	if (!root) {
		return ;
	}

	inorder(root->left);
	root->left = nullptr;
	preNode->right = root;
	preNode = root;
	inorder(root->right);

	return ;
}

/**
 * @brief 给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 * 
 * @param root 
 * @return TreeNode* 
 */
TreeNode* increasingBST(TreeNode* root) {
	// 对于二叉搜索树，中序遍历的结果是递增排列的，因此利用中序遍历构建
	TreeNode *dummy = new TreeNode(0);
	preNode = dummy;
	inorder(root);

	return dummy->right;
}
int main() {

	return 0;
}