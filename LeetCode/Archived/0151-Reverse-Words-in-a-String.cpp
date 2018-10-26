class Solution {
public:
	void reverseWords(string &s) {
		vector<string> strs;
		string tmp = "";
		for (auto a = s.begin(); a != s.end(); a++) {
			if (*a != ' ')
				tmp.push_back(*a);
			else {
				if (tmp != "") {
					strs.push_back(tmp);
					tmp = "";
				}
			}
		}
		if (*s.rbegin() != ' ')
			if (tmp != "")
				strs.push_back(tmp);
		string res = "";
		if (strs.size() == 0) {
			s = "";
			return;
		}
		for (auto a = strs.rbegin(); a != strs.rend(); a++)
			res = res + *a + " ";
		res.erase(res.size() - 1);
		s = res;
	}
};