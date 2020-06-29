var searchInsert = function (nums, target) {
    let len = nums.length;
    if (len == 0) {
        return 0;
    }
    else if (len == 1) {
        return nums[0] < target ? 1 : 0;
    }
    else {
        let midd = Math.floor(len / 2);
        if (nums[midd] < target) {
            let tmp = nums.slice(midd + 1);
            return midd + searchInsert(tmp, target) + 1;
        }
        else {
            let tmp = nums.slice(0, midd);
            return searchInsert(tmp, target);
        }
    }
};
