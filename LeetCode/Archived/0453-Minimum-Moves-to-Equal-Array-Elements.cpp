class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = nums[0];
		for (auto a = nums.begin(); a != nums.end(); a++)
			if (*a < min)
				min = *a;
		int res = 0;
		for (auto a = nums.begin(); a != nums.end(); a++)
			res += *a - min;
		return res;
	}
};