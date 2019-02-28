	class Solution {
	public:
		map<int, int> xmap;
		bool isCousins(TreeNode* root, int x, int y) {
			getMap(root);
			if (xmap[x] == xmap[y]) {
				return false;
			} else {
				x = xmap[x];
				y = xmap[y];
				while (xmap[x] != NULL && xmap[y] != NULL) {
					if (xmap[x] == xmap[y]) {
						return true;
					} else {
						x = xmap[x];
						y = xmap[y];
					}
				}
				return false;
			}
		}
	private:
		void getMap(TreeNode* root) {
			if (root) {
				if (root->left) {
					xmap.insert(pair<int, int>(root->left->val, root->val));
					getMap(root->left);
				}
				if (root->right) {
					xmap.insert(pair<int, int>(root->right->val, root->val));
                    getMap(root->right);
				}
			} else {
				return;
			}
		}
	};