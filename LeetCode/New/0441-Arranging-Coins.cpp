class Solution {
public:
	int arrangeCoins(int n) {
		return (int)(sqrt((double)n * 2 + 0.25001f) - 0.5f);
	}
};

//one line solution