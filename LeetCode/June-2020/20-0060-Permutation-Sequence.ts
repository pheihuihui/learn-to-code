function getPermutation(n: number, k: number): string {
    let fac = [1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    let arr = []
    for (let a = 1; a <= n; a++) {
        arr.push(a)
    }
    return _getPermutation(arr, k, fac)
};

function _getPermutation(arr: number[], k: number, fac: number[]): string {
    if (arr.length == 1) {
        return arr[0].toString()
    } else {
        let len = arr.length
        let lem = fac[len - 2]
        let a = Math.floor((k - 1) / lem)
        let b = (k - 1) % lem + 1
        let aa = arr[a]
        let ind = arr.findIndex(x => x == aa)
        arr.splice(ind, 1)
        return aa.toString().concat(_getPermutation(arr, b, fac))
    }
}