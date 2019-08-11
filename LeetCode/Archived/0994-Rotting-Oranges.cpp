	class Solution {
	public:
		int orangesRotting(vector<vector<int>>& grid) {
			int rottens = countRottens(grid);
			int all = countAll(grid);
			int res = 0;
			if (rottens == 0 && all != 0) {
				return -1;
			}
			while (rottens != all) {
				spread(grid);
				int tmp = countRottens(grid);
				if (tmp == rottens) {
					return -1;
				} else {
					rottens = tmp;
					res += 1;
				}
			}
			return res;
		}
	private:
		void spread(vector<vector<int>>& grid) {
			vector<vector<int>> gridcopy = grid;
			int x = grid.size();
			int y = grid[0].size();
			for (int i = 0; i < x; i++) {
				for (int u = 0; u < y; u++) {
					if (grid[i][u] == 2) {
						if (i - 1 >= 0) {
							int tmp = grid[i - 1][u];
							if (tmp == 1) {
								gridcopy[i - 1][u] = 2;
							}
						}
						if (i + 1 < x) {
							int tmp = grid[i + 1][u];
							if (tmp == 1) {
								gridcopy[i + 1][u] = 2;
							}
						}
						if (u - 1 >= 0) {
							int tmp = grid[i][u - 1];
							if (tmp == 1) {
								gridcopy[i][u - 1] = 2;
							}
						}
						if (u + 1 < y) {
							int tmp = grid[i][u + 1];
							if (tmp == 1) {
								gridcopy[i][u + 1] = 2;
							}
						}
					}
				}
			}
			grid = gridcopy;
		}
		int countRottens(vector<vector<int>>& grid) {
			int res = 0;
			int x = grid.size();
			int y = grid[0].size();
			for (int i = 0; i < x; i++) {
				for (int u = 0; u < y; u++) {
					if (grid[i][u] == 2) {
						res += 1;
					}
				}
			}
			return res;
		}
		int countAll(vector<vector<int>>& grid) {
			int res = 0;
			int x = grid.size();
			int y = grid[0].size();
			for (int i = 0; i < x; i++) {
				for (int u = 0; u < y; u++) {
					if (grid[i][u] == 1 || grid[i][u] == 2) {
						res += 1;
					}
				}
			}
			return res;
		}
	};