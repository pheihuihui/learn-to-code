let findPeakElement = function (nums: number[]) {
    let len = nums.length
    if (len > 1) {
        if (nums[0] > nums[1]) {
            return 0
        } else if (nums[len - 1] > nums[len - 2]) {
            return len - 1
        }
    }
    for (let u = 1; u < len - 1; u++) {
        if (nums[u - 1] < nums[u] && nums[u] > nums[u + 1]) {
            return u
        }
    }
    return 0
}