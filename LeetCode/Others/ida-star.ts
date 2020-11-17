const position = (n: number) => {
    if (n == 0) {
        return [3, 3]
    }
    let y = Math.floor(n / 4 - 0.1)
    let x = n - y * 4 - 1
    return [x, y]
}

class Table {
    public list: number[][]
    public blankX: number
    public blankY: number

    constructor(arr?: number[][]) {
        this.list = []
        if (arr) {
            arr.forEach((v, i) => {
                v.forEach((w, u) => {
                    if (this.list[i]) {
                        this.list[i][u] = w
                    } else {
                        this.list[i] = [w]
                    }
                    if (w == 0) {
                        this.setBlankPos(u, i)
                    }
                })
            })
        }
    }

    setBlankPos(x: number, y: number) {
        this.blankX = x
        this.blankY = y
    }

    getBlankX() {
        return this.blankX
    }

    getBlankY() {
        return this.blankY
    }

    equalsTo(arr: number[][]) {
        return arr.toString() == this.list.toString()
    }

    getManhattanDistance() {
        let res = 0
        this.list.forEach((v, i) => {
            v.forEach((w, u) => {
                if (w != 0) {
                    let tmp = Math.abs(position(w)[0] - u) + Math.abs(position(w)[1] - i)
                    console.log(tmp)
                    res += tmp
                }
            })
        })
        return res
    }
}

let n: number
let maxLim: number
let m: number

let goal = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 0]]

let found = false

let table = new Table()
let template = new Table()

function moveBlank(t: Table, d: number, preD: number, depth: number) {
    if (d + preD == 0) {
        return
    }
    template = new Table(t.list)
    //console.log(template.blankX, template.blankY)
    let xx = template.getBlankX()
    let yy = template.getBlankY()
    let tx = 0
    let ty = 0
    switch (d) {
        case 1:
            tx = xx
            ty = yy - 1
            break
        case -1:
            tx = xx
            ty = yy + 1
            break
        case 2:
            tx = xx - 1
            ty = yy
            break
        case -2:
            tx = xx + 1
            ty = yy
            break
    }
    template.list[xx][yy] = template.list[tx][ty]
    template.list[tx][ty] = 0
    //console.log(tx, ty)
    template.setBlankPos(ty, tx)
    if (template.getManhattanDistance() + depth <= maxLim && !found) {
        DFS(template, depth + 1, d)
        if (found) {
            return
        }
    } else {
        m = Math.min(m, template.getManhattanDistance() + depth)
    }
}

function DFS(t: Table, depth: number, preD: number) {
    if (found) {
        return
    }
    if (t.equalsTo(goal)) {
        found = true
        maxLim = depth
        return
    }
    if (depth > maxLim) {
        return
    }
    let xx = t.getBlankX()
    let yy = t.getBlankY()
    if (yy > 0) {
        moveBlank(t, 2, preD, depth)
    }
    if (yy < 3) {
        moveBlank(t, -2, preD, depth)
    }
    if (xx > 0) {
        moveBlank(t, 1, preD, depth)
    }
    if (xx < 3) {
        moveBlank(t, -1, preD, depth)
    }
}


let inputs = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 0, 15]]


function main(input: number[][]) {
    table = new Table(input)
    console.log(table.list)
    table.list.forEach((v, i) => {
        v.forEach((w, u) => {
            if (w == 0) {
                table.setBlankPos(u, i)
            }
        })
    })

    maxLim = table.getManhattanDistance()

    found = false
    console.log(maxLim)

    while (!found && maxLim <= 100) {
        m = 100000
        DFS(table, 0, 0)
        if (!found) {
            maxLim += 1
        }
    }

    console.log(maxLim)
}

main(inputs)

// let test = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 0, 15]]
// let tb = new Table(test)
// console.log(tb.equalsTo(goal))