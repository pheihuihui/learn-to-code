class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto a = s.begin(); a != s.end(); a++) {
			res *= 26;
			res += *a - 64;
		}
		return res;
	}
};