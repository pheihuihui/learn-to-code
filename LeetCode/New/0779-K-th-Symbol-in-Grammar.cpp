	class Solution {
	public:
		int kthGrammar(int N, int K) {
			if (N == 1) {
				return 0;
			} else if (N == 2) {
				if (K == 1) {
					return 0;
				} else {
					return 1;
				}
			} else {
				int len = 1 << (N - 1);
				if (K <= len / 2) {
					return kthGrammar(N - 1, K);
				} else if (K <= len * 3 / 4) {
					return kthGrammar(N - 1, K - len / 4);
				} else {
					return kthGrammar(N - 2, K - len * 3 / 4);
				}
			}
		}
	};