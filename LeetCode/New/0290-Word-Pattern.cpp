class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<char> keys;
		vector<string> vals;
		for (auto a = pattern.begin(); a != pattern.end(); a++)
			keys.push_back(*a);
		vals = split(str, " ");
		if (keys.size() != vals.size())
			return false;
		else {
			map<char, string> tmp;
			for (int i = 0; i < keys.size(); i++) {
				if (tmp.find(keys[i]) != tmp.end()) {
					if (tmp.find(keys[i])->second != vals[i])
						return false;
					else
						continue;
				}
				else {
					tmp.insert(make_pair(keys[i], vals[i]));
				}
			}
			map<string, char> tmq;
			for (int i = 0; i < vals.size(); i++) {
				if (tmq.find(vals[i]) != tmq.end()) {
					if (tmq.find(vals[i])->second != keys[i])
						return false;
					else
						continue;
				}
				else {
					tmq.insert(make_pair(vals[i], keys[i]));
				}
			}
		}
		return true;
	}
private:
	vector<string> split(const string& str, const string& delim) {
		vector<string> res;
		if ("" == str) 
			return res;
		char *strs = new char[str.length() + 1];
		strcpy(strs, str.c_str());
		char *d = new char[delim.length() + 1];
		strcpy(d, delim.c_str());
		char *p = strtok(strs, d);
		while (p) {
			string s = p;
			res.push_back(s);
			p = strtok(NULL, d);
		}
		return res;
	}
};