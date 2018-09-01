class Solution {
public:
	int findNthDigit(int n) {
		int n1 = 10;
		int n2 = 90 * 2 + n1;
		int n3 = 900 * 3 + n2;
		int n4 = 9000 * 4 + n3;
		int n5 = 90000 * 5 + n4;
		int n6 = 900000 * 6 + n5;
		int n7 = 9000000 * 7 + n6;
		int n8 = 90000000 * 8 + n7;
		int n9 = INT_MAX;
		if (n < n1)
			return n;
		else if (n < n2) {
			return findx(n, 2, 10, n1);
		}
		else if (n < n3) {
			return findx(n, 3, 100, n2);
		}
		else if (n < n4) {
			return findx(n, 4, 1000, n3);
		}
		else if (n < n5) {
			return findx(n, 5, 10000, n4);
		}
		else if (n < n6) {
			return findx(n, 6, 100000, n5);
		}
		else if (n < n7) {
			return findx(n, 7, 1000000, n6);
		}
		else if (n < n8) {
			return findx(n, 8, 10000000, n7);
		}
		else {
			return findx(n, 9, 100000000, n8);
		}
	}
private:
	int findx(int n, int width, int start, int begin) {
		int num = (n - begin) / width + start;
		int index = (n - begin) % width;
		for (int i = 1; i < width - index; i++)
			num /= 10;
		return num % 10;
	}
};

//too long