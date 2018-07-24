class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else if (root->left == NULL && root->right == NULL)
			return 1;
		else {
			int ldep = minDepth(root->left);
			int rdep = minDepth(root->right);
			if (ldep == 0)
				return rdep + 1;
			if (rdep == 0)
				return ldep + 1;
			return (ldep < rdep ? ldep + 1 : rdep + 1);
		}
	}
};