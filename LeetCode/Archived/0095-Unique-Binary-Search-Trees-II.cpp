	class Solution {
	public:
		vector<TreeNode*> generateTrees(int n) {
			if (n == 0) {
				return vector<TreeNode*>();
			} else {
				return gen(1, n);
			}
		}
	private:
		vector<TreeNode*> gen(int start, int end) {
			vector<TreeNode*> res;
			if (start == end) {
				res.push_back(new TreeNode(start));
			} else if (start > end) {
				res.push_back(NULL);
			} else {
				for (int i = start; i <= end; i++) {
					vector<TreeNode*> lefts = gen(start, i - 1);
					vector<TreeNode*> rights = gen(i + 1, end);
					for (auto a = lefts.begin(); a != lefts.end(); a++) {
						for (auto b = rights.begin(); b != rights.end(); b++) {
							TreeNode* root = new TreeNode(i);
							root->left = *a;
							root->right = *b;
							res.push_back(root);
						}
					}
				}
			}
			return res;
		}
	};