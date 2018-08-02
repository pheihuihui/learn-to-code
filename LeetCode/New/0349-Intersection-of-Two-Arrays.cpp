class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		vector<int> tmp;
		for (auto a = nums1.begin(); a != nums1.end(); a++) {
			if (find(res.begin(), res.end(), *a) == res.end() || find(tmp.begin(), tmp.end(), *a) != tmp.end()) {
				auto m = find(nums2.begin(), nums2.end(), *a);
				if (m != nums2.end())
					res.push_back(*a);
				else
					tmp.push_back(*a);
			}
		}
		return res;
	}
};