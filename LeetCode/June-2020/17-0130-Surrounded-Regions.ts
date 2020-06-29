function solve(board: string[][]): void {
    if (board.length > 2) {
        let hei = board.length
        let wid = board[0].length
        if (wid > 2) {
            for (let a = 0; a < hei; a++) {
                dfs(board, a, 0, [])
            }
            for (let a = 0; a < hei; a++) {
                dfs(board, a, wid - 1, [])
            }
            for (let a = 0; a < wid; a++) {
                dfs(board, 0, a, [])
            }
            for (let a = 0; a < wid; a++) {
                dfs(board, hei - 1, a, [])
            }
            for (let a = 0; a < hei; a++) {
                for (let b = 0; b < wid; b++) {
                    if (board[a][b] == 'O') {
                        board[a][b] = 'X'
                    }
                    if (board[a][b] == 'S') {
                        board[a][b] = 'O'
                    }
                }
            }
        }
    }
};

function dfs(board: string[][], u: number, i: number, walked: string[]) {
    if (board[u] && board[u][i] && board[u][i] == 'O' && walked.findIndex(x => x == u.toString() + ', ' + i.toString()) == -1) {
        walked.push(u.toString() + ', ' + i.toString())
        dfs(board, u, i + 1, walked)
        dfs(board, u, i - 1, walked)
        dfs(board, u + 1, i, walked)
        dfs(board, u - 1, i, walked)
        board[u][i] = 'S'
    }
}