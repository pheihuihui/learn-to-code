class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		TreeNode* root;
		if (postorder.size() != 0)
			root = new TreeNode(*postorder.rbegin());
		else
			return nullptr;
		int rootval = root->val;
		vector<int> inleft, inright;
		auto tmp = inorder.begin();
		for (auto a = inorder.begin(); a != inorder.end(); a++) {
			if (*a == rootval) {
				tmp = a;
				break;
			}
		}
		int index = tmp - inorder.begin();
		for (int i = 0; i < index; i++)
			inleft.push_back(inorder[i]);
		for (int i = index + 1; i < inorder.size(); i++)
			inright.push_back(inorder[i]);
		vector<int> postleft, postright;
		for (int i = 0; i < index; i++)
			postleft.push_back(postorder[i]);
		for (int i = index; i < inorder.size() - 1; i++)
			postright.push_back(postorder[i]);
		root->left = buildTree(inleft, postleft);
		root->right = buildTree(inright, postright);
		return root;
	}
};

//too slow