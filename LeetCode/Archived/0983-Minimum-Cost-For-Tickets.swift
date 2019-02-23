class Solution {
    var recs: [Int: Int] = [Int: Int]()
    func mincostTickets(_ days: [Int], _ costs: [Int]) -> Int {
        let len = days.count
        if len == 0 {
            return 0
        } else if len == 1 {
            return costs[0]
        } else {
            let begin = days[0]
            if recs[begin] != nil {
                return recs[begin]!
            } else {
                var tailA = days
                tailA.removeFirst()
                var tailB = tailA
                while tailB.count != 0 {
                    if tailB[0] < begin + 7 {
                        tailB.removeFirst()
                    } else {
                        break
                    }
                }
                var tailC = tailB
                while tailC.count != 0 {
                    if tailC[0] < begin + 30 {
                        tailC.removeFirst()
                    } else {
                        break
                    }
                }
                let plan1 = costs[0] + mincostTickets(tailA, costs)
                let plan2 = costs[1] + mincostTickets(tailB, costs)
                let plan3 = costs[2] + mincostTickets(tailC, costs)
                let res = min(plan1, plan2, plan3)
                recs[begin] = res
                return res
            }
        }
    }
}