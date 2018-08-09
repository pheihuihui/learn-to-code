class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<char> tmp;
		tmp.resize(magazine.size());
		tmp.assign(magazine.begin(), magazine.end());
		for (auto a = ransomNote.begin(); a != ransomNote.end(); a++)
			if (find(tmp.begin(), tmp.end(), *a) != tmp.end())
				tmp.erase(find(tmp.begin(), tmp.end(), *a));
			else
				return false;
		return true;
	}
};