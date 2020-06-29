var reverseString = function (s) {
    let len = s.length
    for (let u = 0; u < len / 2; u++) {
        [s[u], s[len - u - 1]] = [s[len - u - 1], s[u]]
    }
};