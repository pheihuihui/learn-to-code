class Solution {
    func pancakeSort(_ A: [Int]) -> [Int] {
        var H = A
        var res: [Int] = [Int]()
        let len = A.count
        if len == 0 || len == 1 {
            return [Int]()
        }
        for i in (2...len).reversed() {
            for u in 1...i {
                if H[u - 1] == i {
                    if i == u {
                        break
                    }
                    else {
                        if u != 1 {
                            res.append(u)
                            reverseHead(&H, u)
                        }
                        if i != 1 {
                            res.append(i)
                            reverseHead(&H, i)
                        }
                    }
                    break
                }
            }
        }
        return res
    }
    
    private func reverseHead(_ H: inout [Int], _ n: Int) {
        if H.count == 0 || H.count == 1 || n == 0 || n == 1 {
            return
        } else {
            for i in 0...(n / 2 - 1) {
                let tmp = H[i]
                H[i] = H[n - i - 1]
                H[n - i - 1] = tmp
            }
        }
    }
}