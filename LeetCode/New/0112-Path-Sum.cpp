class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		else if (root->val == sum && root->left == nullptr && root->right == nullptr)
			return true;
		else
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};