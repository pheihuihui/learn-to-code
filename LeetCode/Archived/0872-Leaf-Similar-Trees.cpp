class Solution {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		if (getLeafs(root1) == getLeafs(root2))
			return true;
		else
			return false;
	}
private:
	vector<int> getLeafs(TreeNode* node) {
		vector<int> res;
		if (node == NULL)
			return res;
		else if (node->left == NULL && node->right == NULL)
			res.push_back(node->val);
		else {
			vector<int> tmpl = getLeafs(node->left);
			vector<int> tmpr = getLeafs(node->right);
			for (auto a = tmpl.begin(); a != tmpl.end(); a++)
				res.push_back(*a);
			for (auto b = tmpr.begin(); b != tmpr.end(); b++)
				res.push_back(*b);
		}
		return res;
	}
};