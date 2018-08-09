int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int res = n;
		int gap = n / 2;
		while (gap > 4) {
			if (guess(res) == 1) 
				res += gap;
			else if (guess(res) == -1)
				res -= gap;
			gap /= 2;
		}
		for (int i = ((res - 20) > 1 ? (res - 20) : 1); i < res + 20; i++)
			if (guess(i) == 0)
				return i;
		return res;
	}
};