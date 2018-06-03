#include "ctype.h"
#include <string>
#include <regex>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) {
			return false;
		}
		vector<char> ss, tt;
		for (int i = 0; i < s.length(); i++) {
			ss.push_back(s[i]);
			tt.push_back(t[i]);
		}
		sort(ss.begin(), ss.end());
		sort(tt.begin(), tt.end());
		if (ss == tt) {
			return true;
		}
		else {
			return false;
		}
	}
};