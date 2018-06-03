public class Solution
{
    public void Rotate(int[,] matrix)
    {
        if(matrix.GetLength(0) == 0 || matrix.GetLength(0) == 1)
        {
            return;
        }
        int len = matrix.GetLength(0);
        for(int i = 0; i < (len + 1) / 2; i++)
        {
            for(int j = i; j < len - 1 - i; j++)
            {
                Change(ref matrix[i, j], ref matrix[len - 1 - j, i], ref matrix[len - 1 - i, len - 1 - j], ref matrix[j, len - 1 - i]);
            }
        }
    }
    public void Change(ref int a, ref int b, ref int c, ref int d)
    {
        int tmp = a;
        a = b;
        b = c;
        c = d;
        d = tmp;
    }
}