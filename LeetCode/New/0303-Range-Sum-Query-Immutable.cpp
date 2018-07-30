class NumArray {
public:
	NumArray(vector<int> nums) {
		vec = nums;
	}

	int sumRange(int i, int j) {
		int res = 0;
		for (int a = i; a <= j; a++)
			res += vec[a];
		return res;
	}
private:
	vector<int> vec;
};