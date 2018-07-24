#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int res = 0;
		for (auto a = s.end() - 1; a >= s.begin(); a--) {
			if (*a == ' ' && res == 0)
				continue;
			else if (*a == ' ')
				return res;
			else
				res++;
		}
		return res;
	}
};