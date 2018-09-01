class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		vector<int> initvec;
		walk(initvec, root, sum);
		return times;
	}
private:
	int times = 0;
	void walk(vector<int> vec, TreeNode* node, int sum) {
		vector<int> tmp = vec;
		tmp.push_back(node->val);
		int ini = 0;
		for (auto a = tmp.rbegin(); a != tmp.rend(); a++) {
			ini += *a;
			if (ini == sum)
				times += 1;
		}
		if (node->left != NULL)
			walk(tmp, node->left, sum);
		if (node->right != NULL)
			walk(tmp, node->right, sum);
	}
};

//slow