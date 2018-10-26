class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		else {
			vector<int> tmp = postorderTraversal(root->left);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
			tmp = postorderTraversal(root->right);
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				res.push_back(*a);
			res.push_back(root->val);
		}
		return res;
	}
};

//try iteratively