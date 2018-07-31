class Solution {
public:
	string reverseVowels(string s) {
		string vows = "aeiouAEIOU";
		vector<char> vv;
		for (auto a = s.begin(); a != s.end(); a++)
			if (find(vows.begin(), vows.end(), *a) != vows.end())
				vv.push_back(*a);
		if (vv.size() == 0)
			return s;
		int tmp = 0;
		string res = "";
		for (int i = 0; i < s.size(); i++) {
			if (find(vows.begin(), vows.end(), s[i]) != vows.end()) {
				res.push_back(vv[vv.size() - tmp - 1]);
				tmp += 1;
			}
			else
				res.push_back(s[i]);
		}
		return res;
	}
};