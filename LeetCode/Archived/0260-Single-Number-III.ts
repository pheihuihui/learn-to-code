function singleNumberIII(nums: number[]): number[] {
    let ss = nums.reduce((pre, cur) => {
        if (pre.has(cur)) {
            pre.delete(cur)
        } else {
            pre.add(cur)
        }
        return pre
    }, new Set<number>())
    return Array.from(ss)
};