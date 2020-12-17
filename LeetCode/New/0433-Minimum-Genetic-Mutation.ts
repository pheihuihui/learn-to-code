function minMutation(start: string, end: string, bank: string[]): number {
    let stbank = new Set(bank)
    if (!stbank.has(end)) return -1
    let arr = [] as { gene: string, steps: number }[]
    arr.push({ gene: start, steps: 0 })
    while (arr.length != 0) {
        let tmp = arr.shift()
        let cur = tmp.gene
        let n = tmp.steps
        if (cur == end) return n
        for (const iterator of stbank) {
            if (diff(iterator, cur) == 1) {
                arr.push({ gene: iterator, steps: n + 1 })
                stbank.delete(iterator)
            }
        }
    }
    return -1
};

function diff(str1: string, str2: string): number {
    if (str1.length != str2.length) return -1
    let ret = str1.split('').reduce((pre, cur, ind) => {
        let res = pre
        if (cur != str2[ind]) {
            res += 1
        }
        return res
    }, 0)
    return ret
}
