public class Solution
{
    public int[] FindDiagonalOrder(int[,] matrix)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        int[] res = new int[rows * cols];
        List<int> reslist = new List<int>();
        for(int i = 0; i < rows + cols - 1; i++)
        {
            int indexsum = i;
            List<int> tmp = new List<int>();
            if(indexsum % 2 == 1)
            {
                for(int j = 0; j <= indexsum; j++)
                {
                    if (j < rows && indexsum - j < cols)
                        tmp.Add(matrix[j, indexsum - j]);
                }
            }
            else
            {
                for(int j = indexsum; j >= 0; j--)
                {
                    if (j < rows && indexsum - j < cols)
                        tmp.Add(matrix[j, indexsum - j]);
                }
            }
            reslist.AddRange(tmp);
        }
        res = reslist.ToArray();
        return res;
    }
}

//too slow