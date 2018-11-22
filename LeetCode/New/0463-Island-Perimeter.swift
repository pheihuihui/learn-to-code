class Solution {
    func islandPerimeter(_ grid: [[Int]]) -> Int {
        var res: Int = 0
        let xx = grid[0].count
        let yy = grid.count
        for i in 0 ..< xx {
            for j in 0 ..< yy {
                res += getSingleLandPerimeter(i, j, grid)
            }
        }
        return res
    }
    func getSingleLandPerimeter(_ x: Int, _ y: Int, _ grid: [[Int]]) -> Int {
        let xx = grid[0].count
        let yy = grid.count
        if grid[y][x] == 0 {
            return 0
        } else {
            var res: Int = 4
            if x - 1 >= 0 {
                if grid[y][x - 1] == 1 {
                    res -= 1
                }
            }
            if x + 1 < xx {
                if grid[y][x + 1] == 1 {
                    res -= 1
                }
            }
            if y - 1 >= 0 {
                if grid[y - 1][x] == 1 {
                    res -= 1
                }
            }
            if y + 1 < yy {
                if grid[y + 1][x] == 1 {
                    res -= 1
                }
            }
            return res
        }
    }
}