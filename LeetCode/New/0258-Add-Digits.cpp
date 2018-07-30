class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;
		else {
			int tmp = 0;
			while (num != 0) {
				tmp += num % 10;
				num /= 10;
			}
			return addDigits(tmp);
		}
	}
};