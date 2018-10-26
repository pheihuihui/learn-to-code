class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		vector<TreeLinkNode*> nodes{ root };
		while (nodes.size() != 0) {
			if (nodes.size() > 1) {
				for (int i = 0; i < nodes.size() - 1; i++)
					nodes[i]->next = nodes[i + 1];
			}
			nodes = getSub(nodes);
		}
	}
private:
	vector<TreeLinkNode*> getSub(vector<TreeLinkNode*> nodes) {
		vector<TreeLinkNode*> res;
		for (auto a = nodes.begin(); a != nodes.end(); a++) {
			if ((*a)->left != nullptr)
				res.push_back((*a)->left);
			if ((*a)->right != nullptr)
				res.push_back((*a)->right);
		}
		return res;
	}
};
