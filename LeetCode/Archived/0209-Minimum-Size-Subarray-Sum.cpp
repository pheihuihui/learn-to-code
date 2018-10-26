class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int res = len + 1;
		int begin = 0;
		int end = 0;
		int sum = nums[0];
		while (0 <= begin && begin <= end && end <= len - 1) {
			if (sum >= s) {
				if (end - begin + 1 < res) {
					res = end - begin + 1;
					if (res == 1)
						return 1;
					else {
						sum -= nums[begin];
						begin += 1;
						continue;
					}
				}
				else {
					sum -= nums[begin];
					begin += 1;
					continue;
				}
			}
			else {
				if (end <= len - 2) {
					end += 1;
					sum += nums[end];
				}
				else
					break;
			}
		}
		if (res == len + 1)
			return 0;
		else
			return res;
	}
};