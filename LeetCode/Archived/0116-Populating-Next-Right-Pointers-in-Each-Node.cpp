class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		else if (root->left == nullptr && root->right == nullptr)
			return;
		else {
			root->left->next = root->right;
			TreeLinkNode* tmp = root->left->right;
			TreeLinkNode* tmq = root->right->left;
			while (tmp != nullptr && tmq != nullptr) {
				tmp->next = tmq;
				tmp = tmp->right;
				tmq = tmq->left;
			}
			connect(root->left);
			connect(root->right);
		}
	}
};