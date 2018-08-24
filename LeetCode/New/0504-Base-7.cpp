class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0)
			return "0";
		else {
			int pos = num > 0 ? num : -num;
			string res = "";
			while (pos != 0) {
				res.insert(res.begin(), pos % 7 + '0');
				pos /= 7;
			}
			return num > 0 ? res : "-" + res;
		}
	}
};