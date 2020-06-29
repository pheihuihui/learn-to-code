var reconstructQueue = function (people) {
    let len = people.length;
    let res = Array(len).fill(null);
    let sorted = people.reduce((pre, cur, index) => {
        let cur_h = cur[0];
        let cur_num = cur[1];
        if (pre[cur_h] != undefined) {
            pre[cur_h].push(cur_num);
        }
        else {
            pre[cur_h] = [cur_num];
        }
        return pre;
    }, {});
    let allIndexes = res.map((v, i) => i);
    for (const u in sorted) {
        let num_sorted = sorted[u].sort((a, b) => a - b);
        let start = 0;
        for (const t of num_sorted) {
            let index = allIndexes[t - start];
            res[index] = [Number(u), t];
            allIndexes.splice(t - start, 1);
            start += 1;
        }
    }
    return res;
};

// too long too slow