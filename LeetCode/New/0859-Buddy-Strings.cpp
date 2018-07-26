class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() < 2 || B.size() < 2)
			return false;
		else if (A.size() != B.size())
			return false;
		else if (A == B && A.size() > 26)
			return true;
		else if (A == B) {
			for (auto s = A.begin(); s != A.end(); s++) {
				for (auto p = s + 1; p != A.end(); p++)
					if (*s == *p)
						return true;
			}
			return false;
		}
		else if (A != B) {
			string tmpA, tmpB;
			for (int i = 0; i < A.size(); i++)
				if (A[i] != B[i]) {
					tmpA.push_back(A[i]);
					tmpB.push_back(B[i]);
				}
			if (tmpA.size() != 2)
				return false;
			else {
				if (tmpA[0] == tmpB[1] && tmpA[1] == tmpB[0])
					return true;
				else
					return false;
			}
		}
	}
};