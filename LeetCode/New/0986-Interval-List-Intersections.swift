class Solution {
    func intervalIntersection(_ A: [Interval], _ B: [Interval]) -> [Interval] {
        var res = [Interval]()
        if A.count == 0 || B.count == 0 {
            return res
        }
        var startB = 0
        for i in A {
            if B.count - 1 < startB {
                break
            }
            let rangeB: CountableClosedRange = startB...(B.count - 1)
            for u in B[rangeB] {
                if u.start > i.end {
                    break
                }
                if let tmp = getMergedInterval(i, u) {
                    res.append(tmp)
                    if i.end >= u.end {
                        startB += 1
                    }
                } else {
                    if i.start > u.end {
                        startB += 1
                    }
                }
            }
        }
        return res
    }
    
    func getMergedInterval(_ A: Interval, _ B: Interval) -> Interval? {
        let startA = A.start
        let startB = B.start
        let endA = A.end
        let endB = B.end
        if startA > endB || startB > endA {
            return nil
        } else {
            let start = startA > startB ? startA : startB
            let end = endA < endB ? endA : endB
            return Interval(start, end)
        }
    }
}