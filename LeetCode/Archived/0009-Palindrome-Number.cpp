#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		else {
			vector<int> tmp;
			while (x != 0) {
				tmp.push_back(x % 10);
				x /= 10;
			}
			int start = 0;
			int len = tmp.size();
			while (start < (len + 1) / 2) {
				if (tmp[start] != tmp[len - start - 1])
					return false;
				start += 1;
			}
			return true;
		}
	}
};