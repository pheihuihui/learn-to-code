class Solution {
public:
	Node * construct(vector<vector<int>>& grid) {
		Node* res = new Node();
		if (allsame(grid)) {
			res->isLeaf = true;
			res->val = getval(grid);
			res->bottomLeft = NULL;
			res->bottomRight = NULL;
			res->topLeft = NULL;
			res->topRight = NULL;
		}
		else {
			res->isLeaf = false;
			res->val = true;
			vector<vector<int>> topl = getTopLeft(grid);
			vector<vector<int>> topr = getTopRight(grid);
			vector<vector<int>> botl = getBottomLeft(grid);
			vector<vector<int>> botr = getBottomRight(grid);
			vector<vector<int>>& tl = topl;
			vector<vector<int>>& tr = topr;
			vector<vector<int>>& bl = botl;
			vector<vector<int>>& br = botr;
			res->topLeft = construct(tl);
			res->topRight = construct(tr);
			res->bottomLeft = construct(bl);
			res->bottomRight = construct(br);
		}
		return res;
	}
private:
	bool allsame(vector<vector<int>>& grid) {
		int tmp = grid[0][0];
		for (auto a = grid.begin(); a != grid.end(); a++) {
			for (auto b = a->begin(); b != a->end(); b++) {
				if (*b != tmp)
					return false;
			}
		}
		return true;
	}
	bool getval(vector<vector<int>>& grid) {
		if (grid[0][0] == 1)
			return true;
		else
			return false;
	}
	vector<vector<int>> getTopLeft(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> res;
		for (int i = 0; i < n / 2; i++) {
			vector<int> tmp;
			for (int j = 0; j < n / 2; j++) {
				tmp.push_back(grid[i][j]);
			}
			res.push_back(tmp);
		}
		return res;
	}
	vector<vector<int>> getTopRight(vector<vector<int>>& grid){
		int n = grid.size();
		vector<vector<int>> res;
		for (int i = 0; i < n / 2; i++) {
			vector<int> tmp;
			for (int j = n / 2; j < n; j++) {
				tmp.push_back(grid[i][j]);
			}
			res.push_back(tmp);
		}
		return res;
	}
	vector<vector<int>> getBottomLeft(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> res;
		for (int i = n / 2; i < n; i++) {
			vector<int> tmp;
			for (int j = 0; j < n / 2; j++) {
				tmp.push_back(grid[i][j]);
			}
			res.push_back(tmp);
		}
		return res;
	}
	vector<vector<int>> getBottomRight(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> res;
		for (int i = n / 2; i < n; i++) {
			vector<int> tmp;
			for (int j = n / 2; j < n; j++) {
				tmp.push_back(grid[i][j]);
			}
			res.push_back(tmp);
		}
		return res;
	}
};