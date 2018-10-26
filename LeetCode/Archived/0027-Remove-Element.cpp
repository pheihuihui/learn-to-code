class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;
		int len = nums.size();
		int last = len - 1;
		int start = 0;
		for (int i = 0; i <= last; i++) {
			if (nums[i] == val) {
				while (nums[last] == val && last > i)
					last--;
				if (nums[last] == val)
					start = i - 1;
				else {
					nums[i] = nums[last];
					nums[last] = val;
					start = i;
				}
			}
			else
				start = i;
		}
		return start + 1;
	}
};