class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num == 0)
			return false;
		else {
			while (num % 4 == 0)
				num /= 4;
			if (num == 1)
				return true;
			else
				return false;
		}
	}
};