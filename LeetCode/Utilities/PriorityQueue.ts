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

type TTest = {
    a: number,
    b: number
}

let queue = new PriorityQueue<TTest>((a, b) => a.a + a.b > b.a + b.b)

queue.push({ a: 1, b: 2 })
queue.push({ a: 7, b: 9 })
queue.push({ a: 7, b: 6 })
queue.push({ a: 5, b: 10 })
queue.push({ a: 5, b: 2 })

while (!queue.isEmpty()) {
    console.log(queue.pop())
}

export { }