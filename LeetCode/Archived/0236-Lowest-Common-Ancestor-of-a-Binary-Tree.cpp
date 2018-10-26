class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == p || root == q)
			return root;
		else {
			num = 0;
			countNodes(root->left, p, q);
			if (num == 1)
				return root;
			else if (num == 2)
				return lowestCommonAncestor(root->left, p, q);
			else
				return lowestCommonAncestor(root->right, p, q);
		}
	}
private:
	int num = 0;
	void countNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || num == 2)
			return;
		else {
			if (root == p || root == q)
				num += 1;
			countNodes(root->left, p, q);
			countNodes(root->right, p, q);
		}
	}
};

//too slow