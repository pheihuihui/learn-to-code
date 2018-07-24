#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int res = 0;
		int sorted = 0;
		for (auto a = nums.begin(); a != nums.end(); a++) {
			if (*a != val) {
				*(nums.begin() + sorted) = *a;
				sorted++;
			}
			else {
				res++;
			}
		}
		return nums.size() - res;
	}
};