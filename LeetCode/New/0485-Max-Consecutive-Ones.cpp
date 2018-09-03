class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		vector<int> inds;
		inds.push_back(-1);
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] == 0)
				inds.push_back(i);
		inds.push_back(nums.size());
		int res = 0;
		for (int i = 1; i < inds.size(); i++)
			if (inds[i] - inds[i - 1] - 1 > res)
				res = inds[i] - inds[i - 1] - 1;
		return res;
	}
};