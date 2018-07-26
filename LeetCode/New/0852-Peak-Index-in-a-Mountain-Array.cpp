class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (auto t = A.begin(); t != A.end(); t++)
			if (*t > *(t + 1))
				return t - A.begin();
		return 0;
	}
};