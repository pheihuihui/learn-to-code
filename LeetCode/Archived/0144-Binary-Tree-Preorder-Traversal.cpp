class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		else {
			res.push_back(root->val);
			vector<int> tmp = preorderTraversal(root->left);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
			tmp = preorderTraversal(root->right);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
		}
		return res;
	}
};