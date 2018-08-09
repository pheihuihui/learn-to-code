class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		int res = 0;
		if (isLeaf(root->left))
			res += root->left->val;
		else
			res += sumOfLeftLeaves(root->left);
		res += sumOfLeftLeaves(root->right);
		return res;
	}
	bool isLeaf(TreeNode* root) {
		if (root != NULL && root->left == NULL && root->right == NULL)
			return true;
		else
			return false;
	}
};