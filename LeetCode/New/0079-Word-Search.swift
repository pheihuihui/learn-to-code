class Solution {
    func exist(_ board: [[Character]], _ word: String) -> Bool {
        if word.count == 0 {
            return true
        } else if board.count > 0 && board[0].count > 0 {
            let first = word[word.startIndex]
            let hei = board.count
            let wid = board[0].count
            for x in 0 ..< hei {
                for y in 0 ..< wid {
                    if board[x][y] == first {
                        print(x * wid + y)
                        if ex(board, x, y, word, Set<Int>()) {
                            return true
                        }
                    }
                }
            }
            return false
        } else {
            return false
        }
    }

    func ex(_ board: [[Character]], _ posX: Int, _ posY: Int, _ word: String, _ passed: Set<Int>) -> Bool {
        if word.count == 0 {
            return true
        } else if board.count > 0 && board[0].count > 0 {
            let hei = board.count
            let wid = board[0].count
            let hash = posX * wid + posY
            if posX < 0 || posX >= hei || posY < 0 || posY >= wid || passed.contains(hash) {
                return false
            } else {
                if board[posX][posY] == word[word.startIndex] {
                    var newPassed = passed
                    newPassed.insert(hash)
                    var newWord = word
                    newWord.remove(at: newWord.startIndex)
                    return ex(board, posX - 1, posY, newWord, newPassed)
                        || ex(board, posX + 1, posY, newWord, newPassed)
                        || ex(board, posX, posY - 1, newWord, newPassed)
                        || ex(board, posX, posY + 1, newWord, newPassed)
                } else {
                    return false
                }
            }
        } else {
            return false
        }
    }
}
