class Solution {
public:
	string convertToTitle(int n) {
		string res = "";
		while (n != 0) {
			int tmp = n % 26 == 0 ? 26 : n % 26;
			res.insert(res.begin(), tmp + 64);
			n -= tmp;
			n /= 26;
		}
		return res;
	}
};