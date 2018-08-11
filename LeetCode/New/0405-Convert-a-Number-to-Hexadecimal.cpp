class Solution {
public:
	string toHex(int num) {
		string res = "";
		if (num == 0)
			return "0";
		else if (num > 0) {
			while (num != 0) {
				int tmp = num % 16;
				if (tmp < 10)
					res.insert(res.begin(), tmp + '0');
				else
					res.insert(res.begin(), tmp + 'a' - 10);
				num /= 16;
			}
		}
		else {
			uint32_t xx = (uint32_t(INT_MAX) + 1) * 2 + num;
			while (xx != 0) {
				int tmp = xx % 16;
				if (tmp < 10)
					res.insert(res.begin(), tmp + '0');
				else
					res.insert(res.begin(), tmp + 'a' - 10);
				xx /= 16;
			}
		}
		return res;
	}
};