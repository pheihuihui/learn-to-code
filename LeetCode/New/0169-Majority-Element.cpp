class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> tmp;
		int total = 0;
		for (auto a = nums.begin(); a != nums.end(); a++) {
			total += 1;
			if (tmp.find(*a) != tmp.end())
				tmp[*a] += 1;
			else
				tmp.insert(make_pair(*a, 1));
		}
		for (auto b = tmp.begin(); b != tmp.end(); b++) {
			if (b->second > total / 2)
				return b->first;
		}
		return 0;
	}
};