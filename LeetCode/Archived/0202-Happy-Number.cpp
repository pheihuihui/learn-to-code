class Solution {
public:
	bool isHappy(int n) {
		vector<int> tmp;
		while (n != 1) {
			for (auto a = tmp.begin(); a != tmp.end(); a++) {
				if (*a == n)
					return false;
			}
			tmp.push_back(n);
			n = getNext(n);
		}
		return true;
	}
private:
	int getNext(int n) {
		int res = 0;
		while (n != 0) {
			res += (n % 10) * (n % 10);
			n /= 10;
		}
		return res;
	}
};