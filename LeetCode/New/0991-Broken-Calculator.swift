class Solution {
    func brokenCalc(_ X: Int, _ Y: Int) -> Int {
        var res = 0
        if X >= Y {
            return X - Y
        } else {
            if Y % 2 == 0 {
                res += brokenCalc(X, Y / 2) + 1
            } else {
                res += brokenCalc(X, (Y + 1) / 2) + 2
            }
            return res
        }
    }
}