class Solution {
public:
	char findTheDifference(string s, string t) {
		for (auto a = s.begin(); a != s.end(); a++) {
			bool skip = false;
			for (auto b = t.begin(); b != t.end(); b++) {
				if (*b == *a) {
					*b = ' ';
					break;
				}
				if (b == t.end() - 1)
					skip = true;
			}
			if (skip)
				break;
		}
		for (auto s = t.begin(); s != t.end(); s++)
			if (*s != ' ')
				return *s;
		return ' ';
	}
};

//slow