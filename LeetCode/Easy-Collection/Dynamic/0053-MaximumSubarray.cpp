#include "stdafx.h"
#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int start = 0;
		int end = 0;
		int max = INT_MIN;
		int totalSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			totalSum += nums[i];
			int tmp = totalSum;
			for (int j = 0; j <= i; j++) {
				if (tmp > max) {
					start = j;
					end = i;
					max = tmp;
				}
				tmp -= nums[j];
			}
		}
		return max;
	}
};

//too slow