	class Solution {
	public:
		TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
			if (root == NULL) {
				return new TreeNode(val);
			} else if (val > root->val) {
				TreeNode* node = new TreeNode(val);
				node->left = root;
				return node;
			} else {
				TreeNode* rr = insertIntoMaxTree(root->right, val);
				root->right = rr;
				return root;
			}
		}
	};