class Solution {
public:
	int thirdMax(vector<int>& nums) {
		for (auto a = nums.begin(); a != nums.end(); a++)
			rank(*a);
		if (thr.second)
			return thr.first;
		else
			return one.first;
	}
private:
	pair<int, bool> one = make_pair(INT_MIN, false);
	pair<int, bool> two = make_pair(INT_MIN, false);
	pair<int, bool> thr = make_pair(INT_MIN, false);
	void rank(int a) {
		if (a > one.first) {
			thr = two;
			two = one;
			one.first = a;
			one.second = true;
		}
		else if (a == one.first)
			one.second = true;
		else if (a > two.first) {
			thr = two;
			two.first = a;
			two.second = true;
		}
		else if (a == two.first)
			two.second = true;
		else if (a > thr.first) {
			thr.first = a;
			thr.second = true;
		}
		else if (a == thr.first)
			thr.second = true;
		else
			return;
	}
};