class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		vector<Node*> tmp{ root };
		while (!isAllNull(tmp)) {
			vector<int> layer;
			for (auto a = tmp.begin(); a != tmp.end(); a++)
				if (*a != nullptr)
					layer.push_back((*a)->val);
			res.push_back(layer);
			tmp = getNext(tmp);
		}
		return res;
	}
private:
	vector<Node*> getNext(vector<Node*>& nodes) {
		vector<Node*> res;
		for (auto a = nodes.begin(); a != nodes.end(); a++) {
			if (*a != nullptr) {
				for (auto b = (*a)->children.begin(); b != (*a)->children.end(); b++)
					res.push_back(*b);
			}
		}
		return res;
	}
	bool isAllNull(vector<Node*>& nodes) {
		if (nodes.size() == 0)
			return true;
		for (auto a = nodes.begin(); a != nodes.end(); a++)
			if (*a != nullptr)
				return false;
		return true;
	}
};