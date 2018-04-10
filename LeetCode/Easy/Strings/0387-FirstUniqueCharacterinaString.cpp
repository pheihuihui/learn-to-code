#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		if (s.length() == 1) {
			return 0;
		}
		int res = -1;
		bool isBreak = false;
		vector<char> v;
		for (int i = 0; i < s.length(); i++) {
			isBreak = false;
			if (isDuplicate(s[i], v)) {
				continue;
			}
			else {
				for (int j = i + 1; j < s.length(); j++) {
					if (s[j] == s[i]) {
						v.push_back(s[i]);
						isBreak = true;
						break;
					}
				}
				if (!isBreak) {
					res = i;
					break;
				}
			}
		}
		return res;
	}
private:
	bool isDuplicate(char c, vector<char> cc) {
		if (cc.size() == 0) {
			return false;
		}
		vector<char>::iterator ret;
		ret = find(cc.begin(), cc.end(), c);
		if (ret != cc.end()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//too complecated