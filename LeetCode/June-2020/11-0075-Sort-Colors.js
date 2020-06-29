var sortColors = function (nums) {
    let tmp = [0, 0, 0];
    for (const u of nums) {
        if (u == 0) {
            tmp[0] += 1;
        }
        if (u == 1) {
            tmp[1] += 1;
        }
        if (u == 2) {
            tmp[2] += 1;
        }
    }
    for (let index = 0; index < tmp[0]; index++) {
        nums[index] = 0;
    }
    for (let index = tmp[0]; index < tmp[0] + tmp[1]; index++) {
        nums[index] = 1;
    }
    for (let index = tmp[0] + tmp[1]; index < tmp[0] + tmp[1] + tmp[2]; index++) {
        nums[index] = 2;
    }
};