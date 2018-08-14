class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		levelOrder(root, 0);
		vector<vector<int>> res;
		for (auto a = xmap.begin(); a != xmap.end(); a++)
			res.push_back(a->second);
		return res;
	}
private:
	map<int, vector<int>> xmap;
	void levelOrder(Node* node, int index) {
		if (node == NULL)
			return;
		else {
			if (xmap.find(index) != xmap.end()) {
				xmap[index].push_back(node->val);
			}
			else
				xmap.insert(make_pair(index, vector<int>{node->val}));
			for (auto a = node->children.begin(); a != node->children.end(); a++)
				levelOrder(*a, index + 1);
		}
	}
};