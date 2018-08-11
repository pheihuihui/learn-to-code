class Solution {
public:
	int longestPalindrome(string s) {
		map<char, int> xmap;
		for (int i = 'a'; i <= 'z'; i++)
			xmap.insert(make_pair(i, 0));
		for (int i = 'A'; i <= 'Z'; i++)
			xmap.insert(make_pair(i, 0));
		for (auto a = s.begin(); a != s.end(); a++)
			xmap[*a] += 1;
		int odd = 0;
		int even = 0;
		for (auto a = xmap.begin(); a != xmap.end(); a++) {
			if (a->second % 2 == 0)
				even += a->second;
			else {
				even += a->second - 1;
				odd += 1;
			}
		}
		if (odd > 0)
			return even + 1;
		else
			return even;
	}
};