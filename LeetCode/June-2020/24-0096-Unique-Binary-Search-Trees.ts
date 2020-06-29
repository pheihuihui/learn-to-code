function numTrees(n: number): number {
    let dp: number[] = []
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    for (let u = 3; u <= n; u++) {
        let tmp = 0
        for (let i = 0; i < u; i++) {
            tmp += dp[i] * dp[u - i - 1]
        }
        dp[u] = tmp
    }
    return dp[n]
};