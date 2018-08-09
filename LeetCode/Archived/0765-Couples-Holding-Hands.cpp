class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int coups = row.size() / 2;
		for (int i = 0; i < coups; i++) {
			if (row[2 * i] % 2 == 0) {
				if(row[2 * i + 1] != row[2 * i] + 1 )
					for (int a = 2 * i + 2; a < row.size(); a++) {
						if (row[a] == row[2 * i] + 1)
							swapInt(row[a], row[2 * i + 1]);
					}
			}
			if (row[2 * i] % 2 == 1) {
				if (row[2 * i + 1] != row[2 * i] - 1)
					for (int a = 2 * i + 2; a < row.size(); a++) {
						if (row[a] == row[2 * i] - 1)
							swapInt(row[a], row[2 * i + 1]);
					}
			}
		}
		return times;
	}
private:
	int times = 0;
	void swapInt(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
		times += 1;
	}
};