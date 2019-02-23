class Solution {
    func sumEvenAfterQueries(_ A: [Int], _ queries: [[Int]]) -> [Int] {
        var B = A
        var ini = 0
        var initArr: [Int] = []
        for i in B {
            if i % 2 == 0 {
                ini += i
            }
        }
        for i in queries {
            let aa = i[0]
            let bb = i[1]
            let tmp = B[bb]
            if tmp % 2 == 0 && aa % 2 == 0 {
                ini += aa
            } else if tmp % 2 == 0 && aa % 2 != 0 {
                ini -= tmp
            } else if tmp % 2 != 0 && aa % 2 == 0 {
                
            } else {
                ini += tmp + aa
            }
            B[bb] += aa
            initArr.append(ini)
        }
        return initArr
    }
}