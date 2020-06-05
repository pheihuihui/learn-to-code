class Solution {
    private sum = 0
    private len: number
    private ww: number[]
    constructor(w: number[]) {
        this.len = w.length
        this.ww = w
        w.forEach(v => {
            this.sum += v
        })
    }

    pickIndex(): number {
        let rd = Math.floor(Math.random() * this.len)
        let chance = this.ww[rd] / this.sum
        let rand = Math.random()

        while (rand > chance) {
            rd = Math.floor(Math.random() * this.len)
            chance = this.ww[rd] / this.sum
            rand = Math.random()
        }

        return rd
    }
}

//too slow