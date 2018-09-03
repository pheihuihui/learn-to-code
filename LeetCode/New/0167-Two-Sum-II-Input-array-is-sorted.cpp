class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		int a = 0;
		int b = len - 1;
		while (numbers[a] + numbers[b] != target) {
			int st = numbers[a];
			int en = numbers[b];
			if (st + en < target)
				a++;
			if (st + en > target)
				b--;
		}
		return vector<int> {a + 1, b + 1};
	}
};