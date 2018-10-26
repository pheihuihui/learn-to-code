 class Solution {
 public:
	 vector<int> spiralOrder(vector<vector<int>>& matrix) {
		 if (matrix.size() == 0)
			 return vector<int>();
		 vector<int> res;
		 int y = matrix.size();
		 int x = matrix[0].size();
		 int sx = 0;
		 int sy = 0;
		 while (x > 0 && y > 0) {
			 if (x == 1) {
				 for (int i = sy; i < y + sy; i++)
					 res.push_back(matrix[i][sx]);
				 break;
			 }
			 if (y == 1) {
				 for (int i = sx; i < x + sx; i++)
					 res.push_back(matrix[sy][i]);
				 break;
			 }
			 for (int i = sx; i < x + sx; i++)
				 res.push_back(matrix[sy][i]);
			 for (int i = sy + 1; i < y + sy; i++)
				 res.push_back(matrix[i][x + sx - 1]);
			 for (int i = sx + x - 2; i >= sx; i--)
				 res.push_back(matrix[y + sy - 1][i]);
			 for (int i = sy + y - 2; i >= sy + 1; i--)
				 res.push_back(matrix[i][sx]);
			 sx += 1;
			 sy += 1;
			 x -= 2;
			 y -= 2;
		 }
		 return res;
	 }
 };