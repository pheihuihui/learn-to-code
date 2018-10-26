class Solution {
public:
	int maxDepth(Node* root) {
		if (root == nullptr)
			return 0;
		else if (root->children.size() == 0)
			return 1;
		else {
			int tmp = 0;
			for (auto a = root->children.begin(); a != root->children.end(); a++) {
				int q = maxDepth(*a);
				if (q > tmp)
					tmp = q;
			}
			return 1 + tmp;
		}
	}
};