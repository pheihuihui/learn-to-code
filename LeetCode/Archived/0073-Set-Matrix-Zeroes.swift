class Solution {
    func setZeroes(_ matrix: inout [[Int]]) {
        var xs: Set<Int> = Set()
        var ys: Set<Int> = Set()
        for i in matrix.indices {
            for u in matrix[i].indices {
                if matrix[i][u] == 0 {
                    xs.insert(Int(i))
                    ys.insert(Int(u))
                }
            }
        }
        for i in matrix.indices {
            for u in matrix[i].indices {
                if xs.contains(Int(i)) || ys.contains(Int(u)) {
                    matrix[i][u] = 0
                }
            }
        }
    }
}

// too slow