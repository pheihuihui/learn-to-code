#include "ctype.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		vector<int> tmp((a.size() > b.size() ? a.size() : b.size()) + 1, 0);
		for (auto t = a.rbegin(); t != a.rend(); t++) {
			int index = t - a.rbegin();
			tmp[index] += (*t - 48);
		}
		for (auto s = b.rbegin(); s != b.rend(); s++) {
			int index = s - b.rbegin();
			tmp[index] += (*s - 48);
		}
		for (auto s = tmp.begin(); s != tmp.end() - 1; s++) {
			if (*s > 1) {
				*s -= 2;
				*(s + 1) += 1;
			}
		}
		if (*(tmp.end() - 1) == 0)
			tmp.erase(tmp.end() - 1);
		string res = "";
		for (auto f = tmp.rbegin(); f != tmp.rend(); f++) {
			res.push_back(*f + 48);
		}
		return res;
	}
};