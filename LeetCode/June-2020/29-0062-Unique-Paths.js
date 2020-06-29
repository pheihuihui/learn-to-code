var uniquePaths = function (m, n) {
    let aa = m + n - 2
    let bb = n - 1
    let down = 1
    let up = 1
    for (let u = aa; u >= aa - bb + 1; u--) {
        up *= u
    }
    for (let u = 1; u <= bb; u++) {
        down *= u
    }
    return up / down
};