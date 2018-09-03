class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int len = nums.size();
		map<int, int> tmp;
		for (int i = 0; i < len; i++) {
			if (tmp.find(nums[i]) != tmp.end())
				tmp[nums[i]] += 1;
			else
				tmp.insert(make_pair(nums[i], 1));
		}
		vector<int> xx;
		for (int i = -10000; i <= 10000; i++)
			if (tmp.find(i) != tmp.end())
				for (int j = 0; j < tmp[i]; j++)
					xx.push_back(i);
		int res = 0;
		for (int i = 0; i < len / 2; i++)
			res += xx[2 * i];
		return res;
	}
};