class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		else if (root->val == sum && root->left == NULL && root->right == NULL)
			return true;
		else
			return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
	}
};