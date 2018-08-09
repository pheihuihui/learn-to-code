class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (getSig(s) == getSig(t))
			return true;
		else
			return false;
	}
private:
	vector<int> getSig(string z) {
		map<char, int> zmap;
		int tmp = 0;
		for (auto a = z.begin(); a != z.end(); a++) {
			if (zmap.find(*a) == zmap.end())
				zmap.insert(make_pair(*a, tmp++));
		}
		vector<int> res;
		for (auto m = z.begin(); m != z.end(); m++) {
			res.push_back(zmap[*m]);
		}
		return res;
	}
};