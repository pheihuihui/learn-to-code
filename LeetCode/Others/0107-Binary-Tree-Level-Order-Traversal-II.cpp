class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int level = 0;
		insertToMap(root, level);
		vector<vector<int>> res;
		for (auto a = tmp.rbegin(); a != tmp.rend(); a++)
			res.push_back(a->second);
		return res;
	}
private:
	map<int, vector<int>> tmp;
	void insertToMap(TreeNode* node, int key) {
		if (node != NULL) {
			if (tmp.find(key) != tmp.end())
				tmp[key].push_back(node->val);
			else {
				vector<int> v;
				tmp.insert(make_pair(key, v));
				tmp[key].push_back(node->val);
			}
			insertToMap(node->left, key + 1);
			insertToMap(node->right, key + 1);
		}
	}
};