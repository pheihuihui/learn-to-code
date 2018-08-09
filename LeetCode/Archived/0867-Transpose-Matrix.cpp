class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> res;
		for (int i = 0; i < A.begin()->size(); i++) {
			vector<int> tmp;
			for (int j = 0; j < A.size(); j++)
				tmp.push_back(A[j][i]);
			res.push_back(tmp);
		}
		return res;
	}
};