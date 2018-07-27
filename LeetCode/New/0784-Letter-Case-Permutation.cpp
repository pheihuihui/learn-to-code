class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		vector<int> index;
		int len = 1;
		for (auto a = S.begin(); a != S.end(); a++)
			if ((*a <= 'z' && *a >= 'a') || (*a <= 'Z' && *a >= 'A')) {
				len *= 2;
				index.push_back(a - S.begin());
			}
		for (int i = 0; i < len; i++)
			res.push_back(getString(S, index, i));
		return res;
	}

	string getString(string ori, vector<int> inds, int ops) {
		string res;
		string opsString;
		while (ops != 0) {
			int tmp = ops % 2;
			if (tmp == 0)
				opsString.push_back('0');
			else
				opsString.push_back('1');
			ops /= 2;
		}
		int tmp = inds.size() - opsString.size();
		for (int i = 0; i < tmp; i++)
			opsString.push_back('0');
		for (int i = 0; i < ori.size(); i++) {
			auto p = find(inds.begin(), inds.end(), i);
			if (p != inds.end())
				res.push_back(convChar(ori[*p], opsString[p - inds.begin()]));
			else
				res.push_back(ori[i]);
		}
		return res;
	}
	char convChar(char c, char op) {
		char tmp = c;
		if (tmp <= 'z' && tmp >= 'a' && op == '1')
			c = toupper(c);
		if (tmp <= 'Z' && tmp >= 'A' && op == '1')
			c = tolower(c);
		return c;
	}
};

//too long