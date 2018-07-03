#include "stdafx.h"
#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

class Solution {
public:
	bool compressed = false;
	int maxSubArray(vector<int>& nums) {
		if (!compressed) {
			nums = compressVector(nums);
			compressed = true;
			return maxSubArray(nums);
		}
		else {
			int len = nums.size();
			if (len < 6) {
				return maxSum(nums);
			}
			else {
				vector<int> left(nums.begin(), nums.begin() + len / 2);
				vector<int> right(nums.begin() + len / 2, nums.end());
				int mid = maxSum(nums, len / 2, len - len / 2);
				int lef = maxSubArray(left);
				int rig = maxSubArray(right);
				if (mid <= lef && rig <= lef)
					return lef;
				if (mid <= rig && lef <= rig)
					return rig;
				return mid;
			}
		}
	}

private:
	vector<int> compressVector(vector<int>& nums) {
		vector<int> comp;
		for (auto n = nums.begin(); n != nums.end(); n++) {
			if (comp.size() == 0)
				comp.push_back(*n);
			else {
				if (*(comp.end() - 1) >= 0 && *n >= 0)
					*(comp.end() - 1) += *n;
				else
					comp.push_back(*n);
			}
		}
		return comp;
	}
	int getSum(vector<int>& nums, int a, int b) {
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += nums[i];
		}
		return sum;
	}
	int maxSum(vector<int>& nums) {
		int leng = nums.size();
		int tmp = INT_MIN;
		for (int i = 0; i < leng; i++) {
			for (int j = i; j < leng; j++) {
				int tmpSum = getSum(nums, i, j);
				if (tmpSum > tmp)
					tmp = tmpSum;
			}
		}
		return tmp;
	}
	int maxSum(vector<int>& nums, int left, int right) {
		int tmp = INT_MIN;
		for (int i = 0; i < left; i++) {
			for (int j = left; j < left + right; j++) {
				int tmpSum = getSum(nums, i, j);
				if (tmpSum > tmp)
					tmp = tmpSum;
			}
		}
		return tmp;
	}
};

//devide and conquer
//Time Limit Exceeded