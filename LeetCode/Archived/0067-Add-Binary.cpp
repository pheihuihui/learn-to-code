class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		bool p = false;
		int len = a.size() > b.size() ? a.size() : b.size();
		int index = 0;
		while (index <= len) {
			char aa = index >= a.size() ? '0' : *(a.rbegin() + index);
			char bb = index >= b.size() ? '0' : *(b.rbegin() + index);
			string tmp = getChar(aa, bb, p);
			res.insert(res.begin(), tmp[1]);
			p = tmp[0] - '0';
			index++;
		}
		if (res != "0" && res[0] == '0')
			res.erase(res.begin());
		return res;
	}
private:
	string getChar(char a, char b, bool c) {
		if (a == '0' && b == '0') {
			if (c)
				return "01";
			else
				return "00";
		}
		else {
			if ((a == '0' && b == '1') || (a == '1' && b == '0')) {
				if (c)
					return "10";
				else
					return "01";
			}
			else {
				if (c)
					return "11";
				else
					return "10";
			}
		}
	}
};
