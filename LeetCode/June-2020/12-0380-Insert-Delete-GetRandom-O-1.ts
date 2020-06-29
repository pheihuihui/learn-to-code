class RandomizedSet {

    private nset: Set<number>

    constructor() {
        this.nset = new Set()
    }

    insert(val: number): boolean {
        if (this.nset.has(val)) {
            return false
        } else {
            this.nset.add(val)
            return true
        }
    }

    remove(val: number): boolean {
        if (this.nset.has(val)) {
            this.nset.delete(val)
            return true
        } else {
            return false
        }
    }

    getRandom(): number {
        let index = Math.floor(Math.random() * this.nset.size)
        return Array.from(this.nset)[index]
    }
}
