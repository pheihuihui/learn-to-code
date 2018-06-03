public class Solution
{
    public bool IsValidSudoku(char[,] board)
    {
        for(int i = 0; i < 9; i++)
        {
            char[] cc = new char[9];
            for (int j = 0; j < 9; j++)
            {
                cc[j] = board[i, j];
            }
            if (!IsValidUnit(cc))
            {
                return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            char[] cc = new char[9];
            for (int j = 0; j < 9; j++)
            {
                cc[j] = board[j, i];
            }
            if (!IsValidUnit(cc))
            {
                return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char[] cc = new char[9];
                cc[0] = board[i * 3, j * 3 + 2];
                cc[1] = board[i * 3, j * 3];
                cc[2] = board[i * 3, j * 3 + 1];
                cc[3] = board[i * 3 + 1, j * 3 + 2];
                cc[4] = board[i * 3 + 1, j * 3];
                cc[5] = board[i * 3 + 1, j * 3 + 1];
                cc[6] = board[i * 3 + 2, j * 3 + 2];
                cc[7] = board[i * 3 + 2, j * 3];
                cc[8] = board[i * 3 + 2, j * 3 + 1];
                if (!IsValidUnit(cc))
                {
                    return false;
                }
            }
        }
        return true;
    }
    public bool IsValidUnit(char[] bb)
    {
        Dictionary<char, bool?> ll = new Dictionary<char, bool?>();
        for(int i = 0; i < bb.Length; i++)
        {
            if(ll.ContainsKey(bb[i]))
            {
                return false;
            }
            else if(bb[i] == '.'){}
            else
            {
                ll.Add(bb[i], true);
            }
        }
        return true;
    }
}