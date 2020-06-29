function isSubsequence(s: string, t: string): boolean {
    if (s.length == 0) {
        return true
    } else {
        let ind = t.indexOf(s[0])
        if (ind == -1) {
            return false
        } else {
            return isSubsequence(s.slice(1), t.slice(ind + 1))
        }
    }
};