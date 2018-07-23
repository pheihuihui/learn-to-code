class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		else if (!isBalanced(root->left) || !isBalanced(root->right))
			return false;
		else {
			int lh = getHeight(root->left);
			int rh = getHeight(root->right);
			if (lh - rh > 1 || lh - rh < -1)
				return false;
		}
		return true;
	}
private:
	int getHeight(TreeNode* node) {
		if (node == NULL)
			return 0;
		else if (node->left == NULL && node->right == NULL)
			return 1;
		else
			return getHeight(node->left) > getHeight(node->right) ? (getHeight(node->left) + 1) : (getHeight(node->right) + 1);
	}
};

//too slow