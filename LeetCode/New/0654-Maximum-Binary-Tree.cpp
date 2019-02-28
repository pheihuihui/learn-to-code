	class Solution {
	public:
		TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
			if (nums.size() == 0) {
				return NULL;
			} else if (nums.size() == 1) {
				return new TreeNode(nums[0]);
			} else {
				size_t index = getMaxIndex(nums);
				vector<int> ll = getLeft(nums, index);
				vector<int> rr = getRight(nums, index);
				TreeNode* root = new TreeNode(nums[index]);
				root->left = constructMaximumBinaryTree(ll);
				root->right = constructMaximumBinaryTree(rr);
				return root;
			}
		}
	private:
		vector<int> getLeft(vector<int>& nums, int index) {
			vector<int> res;
			for (int i = 0; i < index; i++) {
				res.push_back(nums[i]);
			}
			return res;
		}
		vector<int> getRight(vector<int>& nums, int index) {
			int len = nums.size();
			vector<int> res;
			for (int i = index + 1; i < len; i++) {
				res.push_back(nums[i]);
			}
			return res;
		}
		size_t getMaxIndex(vector<int>& nums) {
			size_t res = 0;
			int start = nums[0];
			for (auto a = nums.begin(); a != nums.end(); a++) {
				if (*a > start) {
					res = a - nums.begin();
					start = *a;
				}
			}
			return res;
		}
	};