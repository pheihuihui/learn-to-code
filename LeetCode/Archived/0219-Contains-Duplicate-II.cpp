class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, vector<int>> nmap;
		for (auto a = nums.begin(); a != nums.end(); a++) {
			if (nmap.find(*a) != nmap.end())
				nmap[*a].push_back(a - nums.begin());
			else
				nmap.insert(make_pair(*a, vector<int>{a - nums.begin()}));
		}
		for (auto s = nmap.begin(); s != nmap.end(); s++) {
			if (s->second.size() >= 2) {
				vector<int> tmp = s->second;
				for (auto m = tmp.begin() + 1; m != tmp.end(); m++) {
					if (*m - *(m - 1) <= k)
						return true;
				}
			}
		}
		return false;
	}
};

//slow