	class Solution {
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>> res;
			if (root == NULL) {
				return res;
			} else {
				vector<TreeNode*> lev{ root };
				bool reversed = true;
				while (lev.size() != 0) {
					vector<int> tmp;
					for (auto a = lev.begin(); a != lev.end(); a++) {
						tmp.push_back((*a)->val);
					}
					res.push_back(tmp);
					lev = getNext(lev, reversed);
					reversed = !reversed;
				}
			}
			return res;
		}
	private:
		vector<TreeNode*> getNext(vector<TreeNode*> lv, bool re) {
			vector<TreeNode*> res;
			for (auto a = lv.rbegin(); a != lv.rend(); a++) {
				auto ll = (*a)->left;
				auto rr = (*a)->right;
				if (re) {
					if (rr) res.push_back(rr);
					if (ll) res.push_back(ll);
				} else {
					if (ll) res.push_back(ll);
					if (rr) res.push_back(rr);
				}
			}
			return res;
		}
	};