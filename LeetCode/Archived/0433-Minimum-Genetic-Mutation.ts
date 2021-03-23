// function minMutation(start: string, end: string, bank: string[]): number {
//     let stbank = new Set(bank)
//     if (!stbank.has(end)) return -1
//     let arr = [] as { gene: string, steps: number }[]
//     arr.push({ gene: start, steps: 0 })
//     while (arr.length != 0) {
//         let tmp = arr.shift()
//         let cur = tmp.gene
//         let n = tmp.steps
//         if (cur == end) return n
//         for (const iterator of stbank) {
//             if (diff(iterator, cur) == 1) {
//                 arr.push({ gene: iterator, steps: n + 1 })
//                 stbank.delete(iterator)
//             }
//         }
//     }
//     return -1
// }

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

class PriorityQueue<T> {
    static readonly _top = 0
    static readonly _parent = (i: number) => ((i + 1) >>> 1) - 1
    static readonly _left = (i: number) => (i << 1) + 1
    static readonly _right = (i: number) => (i + 1) << 1

    private _heap: T[]
    private _comparator: (_a: T, _b: T) => boolean

    constructor(comparator: (_a: T, _b: T) => boolean = (a, b) => a > b) {
        this._heap = []
        this._comparator = comparator
    }
    size() {
        return this._heap.length
    }
    isEmpty() {
        return this.size() == 0
    }
    peek() {
        return this._heap[PriorityQueue._top]
    }
    push(...values: T[]) {
        values.forEach(value => {
            this._heap.push(value)
            this._siftUp()
        })
        return this.size()
    }
    pop() {
        const poppedValue = this.peek()
        const bottom = this.size() - 1
        if (bottom > PriorityQueue._top) {
            this._swap(PriorityQueue._top, bottom)
        }
        this._heap.pop()
        this._siftDown()
        return poppedValue
    }
    replace(value: T) {
        const replacedValue = this.peek()
        this._heap[PriorityQueue._top] = value
        this._siftDown()
        return replacedValue
    }
    _greater(i: number, j: number) {
        return this._comparator(this._heap[i], this._heap[j])
    }
    _swap(i: number, j: number) {
        [this._heap[i], this._heap[j]] = [this._heap[j], this._heap[i]]
    }
    _siftUp() {
        let node = this.size() - 1
        while (node > PriorityQueue._top && this._greater(node, PriorityQueue._parent(node))) {
            this._swap(node, PriorityQueue._parent(node))
            node = PriorityQueue._parent(node)
        }
    }
    _siftDown() {
        let node = PriorityQueue._top
        while (
            (PriorityQueue._left(node) < this.size() && this._greater(PriorityQueue._left(node), node)) ||
            (PriorityQueue._right(node) < this.size() && this._greater(PriorityQueue._right(node), node))
        ) {
            let maxChild = (PriorityQueue._right(node) < this.size()
                && this._greater(PriorityQueue._right(node), PriorityQueue._left(node)))
                ? PriorityQueue._right(node) : PriorityQueue._left(node)
            this._swap(node, maxChild)
            node = maxChild
        }
    }
}

function diff1(str1: string, str2: string) {
    if (str1.length != str2.length) return false
    let len = str1.length
    let tmp = 0
    for (let u = 0; u < len; u++) {
        if (str1[u] != str2[u]) {
            tmp += 1
            if (tmp > 1) return false
        }
    }
    if (tmp == 1) return true
    return false
}

type TState = {
    str: string,
    depth: number
}

function minMutation(start: string, end: string, bank: string[]): number {
    let queue = new PriorityQueue<TState>((a, b) => {
        let d1 = diff(a.str, end)
        let d2 = diff(b.str, end)
        return d1 < d2
    })
    let walked = [] as TState[]
    queue.push({ str: start, depth: 0 })
    while (!queue.isEmpty()) {
        console.log(queue)
        let p = queue.pop()
        if (p.str == end) return p.depth
        walked.push(p)
        for (const u of bank) {
            if (diff1(u, p.str)) {
                let st: TState = { str: u, depth: p.depth + 1 }
                if (walked.findIndex(x => x.str == u) == -1) {
                    queue.push(st)
                }
            }
        }
    }
    return -1
}
