	class Solution {
	public:
		double myPow(double x, int n) {
			if (x == 1 || x == -1) {
				if (n % 2 == 0) {
					return 1;
				} else {
					return x;
				}
			} else if (n == 0) {
				return 1;
			} else if (n >= 1) {
				double res = x;
				while (n != 1) {
					res *= x;
					n -= 1;
				}
				return res;
			} else if (n <= -1) {
				double res = 1 / x;
				while (n != -1) {
					res /= x;
					if (res == 0) {
						return 0;
					}
					n += 1;
				}
				return res;
			} else {
				return 1;
			}
		}
	};