class Codec {
public:
	string serialize(TreeNode* root) {
		vector<TreeNode*> nodes;
		vector<TreeNode*> lay{ root };
		while (!isAllNull(lay)) {
			for (auto a = lay.begin(); a != lay.end(); a++)
				nodes.push_back(*a);
			lay = getNextLayer(lay);
		}
		return getStringFromVector(nodes);
	}

	TreeNode* deserialize(string data) {
		vector<TreeNode*> tmp = getVectorFromString(data);
		int len = tmp.size();
		if (len == 0)
			return nullptr;
		else {
			int start = 0;
			int leng = 1;
			int index = start + leng;
			while (index < len) {
				for (int i = start; i < start + leng; i++) {
					if (tmp[i] != nullptr) {
						if (index < len) {
							tmp[i]->left = tmp[index];
							index += 1;
						}
						else
							break;
						if (index < len) {
							tmp[i]->right = tmp[index];
							index += 1;
						}
						else
							break;
					}
				}
				start += leng;
				leng = index - start;
				index = start + leng;
			}
		}
		return tmp[0];
	}

private:
	string getStringFromVector(vector<TreeNode*>& nodes) {
		if (nodes.size() == 0)
			return "[]";
		else {
			string res = "[";
			int index = -1;
			for (auto a = nodes.rbegin(); a != nodes.rend(); a++) {
				if (*a != nullptr) {
					index = nodes.size() - (a - nodes.rbegin()) - 1;
					break;
				}
			}
			for (int i = 0; i <= index; i++) {
				if (nodes[i] != nullptr)
					res += to_string(nodes[i]->val) + ",";
				else
					res += "null,";
			}
			*res.rbegin() = ']';
			return res;
		}
	}

	vector<TreeNode*> getVectorFromString(string& str) {
		vector<TreeNode*> nodes;
		string tmp = "";
		for (auto a = str.begin(); a != str.end(); a++) {
			if (*a != '[' && *a != ',' && *a != ']') {
				tmp.push_back(*a);
			}
			else {
				if (tmp != "") {
					if (tmp == "null")
						nodes.push_back(nullptr);
					else {
						int val = stoi(tmp);
						nodes.push_back(new TreeNode(val));
					}
				}
				tmp = "";
			}
		}
		return nodes;
	}

	vector<TreeNode*> getNextLayer(vector<TreeNode*>& layer) {
		vector<TreeNode*> res;
		for (auto a = layer.begin(); a != layer.end(); a++) {
			if (*a != nullptr) {
				res.push_back((*a)->left);
				res.push_back((*a)->right);
			}
		}
		return res;
	}

	bool isAllNull(vector<TreeNode*>& nodes) {
		if (nodes.size() == 0)
			return true;
		else {
			for (auto a = nodes.begin(); a != nodes.end(); a++)
				if (*a != nullptr)
					return false;
		}
		return true;
	}
};