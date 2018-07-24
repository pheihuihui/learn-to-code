class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (auto a = numbers.begin(); a != numbers.end(); a++) {
			for (auto b = a + 1; b != numbers.end(); b++) {
				if (*a + *b == target)
					return vector<int>{a - numbers.begin() + 1, b - numbers.begin() + 1};
				if (*b == *a)
					break;
			}
		}
	}
};