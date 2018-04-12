#include "ctype.h"
#include <string>
#include <regex>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++) {
			if (isDuplicate(nums1[i], nums2)) {
				res.push_back(nums1[i]);
				deleteFirst(nums1[i], nums2);
			}
		}
		return res;
	}
private:
	bool isDuplicate(int c, vector<int> cc) {
		if (cc.size() == 0) {
			return false;
		}
		vector<int>::iterator ret;
		ret = find(cc.begin(), cc.end(), c);
		if (ret != cc.end()) {
			return true;
		}
		else {
			return false;
		}
	}
	void deleteFirst(int i, vector<int>& nums) {
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
			if (*iter == i) {
				nums.erase(iter);
				break;
			}
		}
	}
};

//slow