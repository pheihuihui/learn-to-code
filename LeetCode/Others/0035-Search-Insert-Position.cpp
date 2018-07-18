#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int res = 0;
		for (auto a = nums.begin(); a != nums.end(); a++) {
			if (*a >= target)
				return res;
			else {
				res++;
			}
		}
		return res;
	}
};