#include "stdafx.h"
#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		if (len == 2)
			return max(nums[0], nums[1]);
		if (len >= 3) {
			dp.push_back(nums[0]);
			dp.push_back(max(nums[0], nums[1]));
			for (int i = 2; i < nums.size(); i++) {
				dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
			}
		}
		return *(dp.end() - 1);
	}
private:
	vector<int> dp;
};