class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return root;
		else {
			invertTree(root->left);
			invertTree(root->right);
			TreeNode* tmp = root->left;
			root->left = root->right;
			root->right = tmp;
			return root;
		}
	}
};