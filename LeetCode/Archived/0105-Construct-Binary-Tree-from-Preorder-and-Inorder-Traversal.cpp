class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return nullptr;
		int rootval = preorder[0];
		int tot = inorder.size();
		TreeNode* root = new TreeNode(rootval);
		vector<int> inleft, inright;
		for (auto a = inorder.begin(); *a != rootval; a++)
			inleft.push_back(*a);
		int left = inleft.size();
		for (int i = left + 1; i < tot; i++)
			inright.push_back(inorder[i]);
		vector<int> preleft, preright;
		for (int i = 1; i < left + 1; i++)
			preleft.push_back(preorder[i]);
		for (int i = left + 1; i < tot; i++)
			preright.push_back(preorder[i]);
		root->left = buildTree(preleft, inleft);
		root->right = buildTree(preright, inright);
		return root;
	}
};