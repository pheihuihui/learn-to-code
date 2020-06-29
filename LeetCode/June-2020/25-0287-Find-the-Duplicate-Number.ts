function findDuplicate(nums: number[]): number {
    let index = nums.findIndex((x, i) => nums.lastIndexOf(x) != i)
    return nums[index]
};