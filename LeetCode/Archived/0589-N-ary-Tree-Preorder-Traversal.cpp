class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		else {
			if (root->children.size() == 0) {
				res.push_back(root->val);
				return res;
			}
			else {
				res.push_back(root->val);
				for (auto a = root->children.begin(); a != root->children.end(); a++) {
					vector<int> tmp = preorder(*a);
					for (auto b = tmp.begin(); b != tmp.end(); b++)
						res.push_back(*b);
				}
				return res;
			}
		}
	}
};