#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s == "") {
			return true;
		}
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
				res += tolower(s[i]);
			}
		}
		int ii = 0;
		int jj = res.length() - 1;
		while (ii < jj) {
			if (res[ii] != res[jj]) {
				return false;
			}
			ii++;
			jj--;
		}
		return true;
	}
};