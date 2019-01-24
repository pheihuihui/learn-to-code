class Solution {
public:
	void recoverTree(TreeNode* root) {
		order.clear();
		vector<int> tmp = getOrder(root);
		int big, small;
		for (auto a = tmp.begin(); a != tmp.end() - 1; a++) {
			if (a == tmp.begin()) {
				if (*a > *(a + 1)) {
					big = *a;
					break;
				}
			}
			else {
				if ((*a > *(a - 1)) && (*a > *(a + 1))) {
					big = *a;
					break;
				}
			}
		}
		for (auto a = tmp.rbegin(); a != tmp.rend() - 1; a++) {
			if (a == tmp.rbegin()) {
				if (*a < *(a + 1)) {
					small = *a;
					break;
				}
			}
			else {
				if ((*a < *(a + 1)) && (*a < *(a - 1))) {
					small = *a;
					break;
				}
			}
		}
		TreeNode* bignode = findNode(root, big);
		TreeNode* smallnode = findNode(root, small);
		bignode->val = small;
		smallnode->val = big;
		order.clear();
		vector<int> tmq = getOrder(root);
	}

private:
	vector<int> order;
	vector<int> getOrder(TreeNode* root) {
		if (root == nullptr)
			return order;
		else if (root->left == nullptr && root->right == nullptr)
			order.push_back(root->val);
		else {
			getOrder(root->left);
			order.push_back(root->val);
			getOrder(root->right);
		}
		return order;
	}
	TreeNode* findNode(TreeNode* root, int num) {
		if (root == nullptr)
			return nullptr;
		else if (root->val == num)
			return root;
		else {
			TreeNode* ll = findNode(root->left, num);
			TreeNode* rr = findNode(root->right, num);
			if (ll == nullptr)
				return rr;
			else
				return ll;
		}
	}
};