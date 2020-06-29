function hIndex(citations: number[]): number {
    let len = citations.length
    let index = citations.findIndex((v, i) => v + i - len >= 0)
    if (index == -1) {
        return 0
    }
    return len - index
};