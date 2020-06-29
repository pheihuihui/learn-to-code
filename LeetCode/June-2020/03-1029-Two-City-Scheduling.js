var twoCitySchedCost = function (costs) {
    let ss = costs.sort((a, b) => (a[0] - a[1] - b[0] + b[1]))
    let res = 0
    for (let u = 0; u < costs.length / 2; u++) {
        res += ss[u][0]
    }
    for (let u = costs.length / 2; u < costs.length; u++) {
        res += ss[u][1]
    }
    return res
};