impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        if nums.len() == 1 {
            return;
        } else {
            let mut index = 0;
            let len = nums.len();
            for u in 0..len - 1 {
                if nums[len - 2 - u] < nums[len - 1 - u] {
                    index = len - 2 - u + 1;
                    break;
                }
            }
            if index == 0 {
                Solution::reverse(nums, 0, len - 1);
                return;
            } else {
                Solution::reverse(nums, index, len - 1);
                for u in index..len {
                    println!("{}", u);
                    if nums[u] > nums[index - 1] {
                        let tmp = nums[u];
                        nums[u] = nums[index - 1];
                        nums[index - 1] = tmp;
                        return;
                    }
                }
            }
        }
    }

    pub fn reverse(nums: &mut Vec<i32>, start: usize, end: usize) {
        let mut st = start;
        let mut en = end;
        while st < en {
            let tmp = nums[st];
            nums[st] = nums[en];
            nums[en] = tmp;
            st += 1;
            en -= 1;
        }
    }
}