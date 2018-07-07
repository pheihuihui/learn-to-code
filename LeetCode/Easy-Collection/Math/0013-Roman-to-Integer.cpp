#include <map>

using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		map<char, int> mp{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
		for (auto a = s.begin(); a != s.end(); a++) {
			if (mp[*a] < mp[*(a + 1)])
				res -= mp[*a];
			else
				res += mp[*a];
		}
		res += *s.end();
		return res;
	}
};