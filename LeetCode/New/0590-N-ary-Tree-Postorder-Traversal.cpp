class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> res;
		insertNodesToVec(res, root);
		return res;
	}
private:
	void insertNodesToVec(vector<int>& vec, Node* root) {
		if (root == nullptr)
			return;
		// else if (root->children.size() == 0)
		// 	vec.push_back(root->val);
		else {
			for (auto a = root->children.begin(); a != root->children.end(); a++)
				insertNodesToVec(vec, *a);
			vec.push_back(root->val);
		}
	}
};