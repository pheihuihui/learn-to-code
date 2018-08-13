class Solution {
public:
	string addStrings(string num1, string num2) {
		vector<int> tmp;
		if (num2.size() > num1.size()) {
			for (auto a = num2.rbegin(); a != num2.rend(); a++)
				tmp.push_back(*a);
			for (auto a = num1.rbegin(); a != num1.rend(); a++)
				tmp[a - num1.rbegin()] += *a - '0';
		}
		else {
			for (auto a = num1.rbegin(); a != num1.rend(); a++)
				tmp.push_back(*a);
			for (auto a = num2.rbegin(); a != num2.rend(); a++)
				tmp[a - num2.rbegin()] += *a - '0';
		}
		for (auto a = tmp.begin(); a != tmp.end() - 1; a++) {
			if (*a - '0' >= 10) {
				*a -= 10;
				*(a + 1) += 1;
			}
		}
		if (*(tmp.end() - 1) - '0' >= 10) {
			*(tmp.end() - 1) -= 10;
			tmp.push_back('1');
		}
		string res = "";
		for (auto a = tmp.rbegin(); a != tmp.rend(); a++)
			res.push_back(*a);
		return res;
	}
};