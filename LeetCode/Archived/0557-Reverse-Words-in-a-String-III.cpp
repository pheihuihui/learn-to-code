class Solution {
public:
	string reverseWords(string s) {
		string res = "";
		string tmp = "";
		for (auto a = s.begin(); a != s.end(); a++) {
			if (*a == ' ') {
				res += tmp;
				res += " ";
				tmp = "";
			}
			else
				tmp.insert(tmp.begin(), *a);
		}
		res += tmp;
		return res;
	}
};