class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int res = 0;
		for (auto a = S.begin(); a != S.end(); a++)
			if (find(J.begin(), J.end(), *a) != J.end())
				res += 1;
		return res;
	}
};