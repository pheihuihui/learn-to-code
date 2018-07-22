class Solution {
public:
	int mySqrt(int x) {
		int res = 46340;
		int gap = res;
		if (x >= res * res)
			return res;
		while (gap > 1) {
			if (res * res > x) {
				gap /= 2;
				res -= gap;
			}
			else if (res * res < x) {
				gap /= 2;
				res += gap;
			}
			else
				return res;
		}
		if (res * res > x) {
			while (true) {
				res -= 1;
				if (res * res <= x)
					return res;
			}
		}
		else if (res * res < x) {
			while (true) {
				res += 1;
				if (res * res > x)
					return res - 1;
				if (res * res == x)
					return res;
			}
		}
		else
			return res;
	}
};