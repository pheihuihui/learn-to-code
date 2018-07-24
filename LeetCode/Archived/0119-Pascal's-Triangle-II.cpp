class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		if (rowIndex == 0)
			return vector<int>{1};
		else if (rowIndex == 1)
			return vector<int>{1, 1};
		else {
			vector<int> last = getRow(rowIndex - 1);
			res.push_back(*last.begin());
			for (auto a = last.begin() + 1; a != last.end(); a++)
				res.push_back(*a + *(a - 1));
			res.push_back(*(last.end() - 1));
		}
		return res;
	}
};