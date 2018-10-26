class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		for (int i = 0; i <= rowIndex; i++)
			res.push_back(getCombs(rowIndex, i));
		return res;
	}
private:
	int getCombs(int down, int up) {
		if (up == 0)
			return 1;
		else if (up == 1)
			return down;
		else
			return (int)((double)getCombs(down, up - 1) / (double)up * (double)(down - up + 1) + 0.01f);
	}
};
