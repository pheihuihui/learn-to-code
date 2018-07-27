class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		conv(root);
		int res = INT_MAX;
		for (auto a = tmp.begin(); a != tmp.end() - 1; a++)
			if (*(a + 1) - *a < res)
				res = *(a + 1) - *a;
		return res;
	}
private:
	vector<int> tmp;
	void conv(TreeNode* root) {
		if (root == NULL)
			return;
		else {
			conv(root->left);
			tmp.push_back(root->val);
			conv(root->right);
		}
		return;
	}
};