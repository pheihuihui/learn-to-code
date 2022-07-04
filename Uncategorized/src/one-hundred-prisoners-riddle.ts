type Room = Record<number, number>

function getRandomRoom() {
    let arr = [...Array(100).keys()].map(a => a + 1).sort((a, b) => Math.random() - 0.5)
    let room: Room = {}
    let brr = [...Array(100).keys()]
    for (const u of brr) {
        room[u + 1] = arr[u]
    }
    return room
}

function getChance(room: Room, num: number) {
    let circles: number[][] = []

    let len = Object.keys(room).length
    while (len != 0) {
        let circle: number[] = []
        let cur = Number(Object.keys(room)[0])
        while (room[cur]) {
            circle.push(cur)
            let _ = cur
            cur = room[cur]
            delete room[_]
        }
        circles.push(circle)
        len = Object.keys(room).length
    }
    let cc = circles.filter(c => c.findIndex(_ => _ == num))[0]
    return cc.length <= 50
}



let count = 0

for (let _ = 0; _ < 1000; _ += 1) {
    let room = getRandomRoom()
    let num = Math.floor(Math.random() * 100)
    let chance = getChance(room, num)
    if (chance) {
        count += 1
    }
}

console.log(count)
