class Solution {
public:
	int trailingZeroes(int n) {
		int fives = 0;
		for (int i = 1; i <= n / 5; i++)
			fives += getPrimes(i, 5) + 1;
		return fives;
	}
private:
	int getPrimes(int n, int m) {
		int res = 0;
		while (n != 0) {
			if (n % m == 0) {
				n /= m;
				res += 1;
			}
			else
				break;
		}
		return res;
	}
};
// too too slow

class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int result=0;
        for(long i=5;n/i>0;i=i*5){
            result+=(n/i);
        }
        return result;
        
    }
};