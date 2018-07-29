class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if ((p->val < root->val && root->val < q->val) || (q->val < root->val && root->val < p->val))
			return root;
		else if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};