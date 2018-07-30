class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return vector<string>();
		else if (root->left == NULL && root->right == NULL)
			return vector<string>{to_string(root->val)};
		else {
			vector<string> ll = binaryTreePaths(root->left);
			vector<string> rr = binaryTreePaths(root->right);
			vector<string> res;
			if (ll.size() == 0 && rr.size() != 0)
				for (auto a = rr.begin(); a != rr.end(); a++)
					res.push_back(to_string(root->val) + "->" + *a);
			else if (ll.size() != 0 && rr.size() == 0)
				for (auto a = ll.begin(); a != ll.end(); a++)
					res.push_back(to_string(root->val) + "->" + *a);
			else if (ll.size() != 0 && rr.size() != 0) {
				for (auto a = ll.begin(); a != ll.end(); a++)
					res.push_back(to_string(root->val) + "->" + *a);
				for (auto a = rr.begin(); a != rr.end(); a++)
					res.push_back(to_string(root->val) + "->" + *a);
			}
			return res;
		}
	}
};