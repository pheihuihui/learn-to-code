class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		else {
			vector<int> tmp = inorderTraversal(root->left);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
			res.push_back(root->val);
			tmp = inorderTraversal(root->right);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
		}
		return res;
	}
};