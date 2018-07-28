class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int fives = 0;
		int tens = 0;
		int twentys = 0;
		for (auto a = bills.begin(); a != bills.end(); a++) {
			if (*a == 5)
				fives += 1;
			else if (*a == 10) {
				fives -= 1;
				tens += 1;
			}
			else {
				fives -= 1;
				twentys += 1;
				if (tens == 0)
					fives -= 2;
				else
					tens -= 1;
			}
			if (fives < 0 || tens < 0)
				return false;
		}
		return true;
	}
};