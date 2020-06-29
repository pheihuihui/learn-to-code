function singleNumberII(nums: number[]): number {
    let ini: Record<number, number> = {}
    nums.forEach(v => {
        if (ini[v]) {
            ini[v] -= 1
        } else {
            ini[v] = 2
        }
        if (ini[v] == 0) {
            delete ini[v]
        }
    })
    for (const key in ini) {
        if (ini.hasOwnProperty(key)) {
            const element = ini[key];
            if (element == 2) {
                return Number(key)
            }
        }
    }
    return 0
};


// genius solution
// var singleNumber = function(nums) {
//     let a = 0, b = 0;
//      for (let i = 0; i < nums.length; i++) {
//             b = (b ^ nums[i]) & ~a;
//             a = (a ^ nums[i]) & ~b;
//     }
//     return b;
// }