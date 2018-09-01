class Solution {
public:
	int countSegments(string s) {
		if (s.length() == 0)
			return 0;
		else {
			vector<string> res;
			string tmp = "";
			for (auto a = s.begin(); a != s.end(); a++) {
				if (*a == ' ') {
					if (tmp != "") {
						res.push_back(tmp);
						tmp = "";
					}
				}
				else {
					tmp.push_back(*a);
				}
			}
			if (tmp != "")
				res.push_back(tmp);
			return res.size();
		}
	}
};