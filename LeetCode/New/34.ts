let searchRange = function (nums: number[], target: number) {
    let len = nums.length
    if (len == 0) {
        return [-1, -1]
    } else {
        if (nums[0] > target || nums[len - 1] < target) {
            return [-1, -1]
        }
    }
    let cur = len
    let pos = 0
    let start = 0
    let end = 0
    let arr: number[] = []
    //let gap = Math.floor(Math.sqrt(len))
    let gap = Math.floor(len / 100 + 1)
    while (pos < len) {
        if (nums[pos] < target) {
            start = pos
        } else if (nums[pos] == target) {
            arr.push(pos)
        } else {
            end = pos
            break
        }
        pos += gap
    }

    for (let u = start; u < len; u++) {
        if (nums[u] == target) {
            start = u
            break
        } else if (nums[u] > target) {
            return [-1, -1]
        }
    }

    if (arr.length > 0) {
        let before = arr.pop()
        end = before
    } else {
        end = start
    }
    for (let u = end; u < len - 1; u++) {
        if (nums[u] == target && nums[u + 1] != target) {
            return [start, u]
        }
    }
    if (nums[len - 1] == target) {
        return [start, len - 1]
    }
    return [-1, -1]
}