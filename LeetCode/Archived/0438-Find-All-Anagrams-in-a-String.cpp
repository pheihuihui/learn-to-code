class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (p.size() > s.size())
			return res;
		else {
			int pp = p.size();
			int ss = s.size();
			map<char, int> pmap = getMap(p);
			map<char, int> initmap = getMap(s.substr(0, pp));
			if (isSameMap(initmap, pmap))
				res.push_back(0);
			for (int i = 1; i <= ss - pp; i++) {
				initmap[s[i - 1]] -= 1;
				initmap[s[i + pp - 1]] += 1;
				if (isSameMap(initmap, pmap))
					res.push_back(i);
			}
		}
		return res;
	}
private:
	map<char, int> getMap(string str) {
		map<char, int> res;
		for (int i = 'a'; i <= 'z'; i++)
			res.insert(make_pair(i, 0));
		for (auto a = str.begin(); a != str.end(); a++)
			res[*a] += 1;
		return res;
	}
	bool isSameMap(map<char, int> a, map<char, int> b) {
		for (int i = 'a'; i <= 'z'; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}
};

//slow