function calculateMinimumHP(dungeon: number[][]): number {
    let hei = dungeon.length
    let wid = dungeon[0].length
    let line = Array(wid).fill(0)
    let dp: number[][] = []
    for (let a = 0; a < hei; a++) {
        dp.push(line.slice())
    }
    let end = dungeon[hei - 1][wid - 1]
    dp[hei - 1][wid - 1] = end < 0 ? 1 - end : 1
    let last = dp[hei - 1][wid - 1]
    for (let u = wid - 2; u >= 0; u--) {
        let cur = dungeon[hei - 1][u]
        let tmp = last - cur <= 0 ? 1 : last - cur
        dp[hei - 1][u] = tmp
        last = tmp
    }
    last = dp[hei - 1][wid - 1]
    for (let u = hei - 2; u >= 0; u--) {
        let cur = dungeon[u][wid - 1]
        let tmp = last - cur <= 0 ? 1 : last - cur
        dp[u][wid - 1] = tmp
        last = tmp
    }

    for (let a = hei - 2; a >= 0; a--) {
        for (let b = wid - 2; b >= 0; b--) {
            let right = dp[a][b + 1]
            let down = dp[a + 1][b]
            let smaller = right < down ? right : down
            let cur = dungeon[a][b]
            dp[a][b] = smaller - cur <= 0 ? 1 : smaller - cur
        }
    }
    return dp[0][0]
};

