public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        int[] tmp = new int[m + n];
        for(int i = 0; i < m; i++)
        {
            tmp[i] = nums1[i];
        }
        for(int i = 0; i < n; i++)
        {
            tmp[i + m] = nums2[i];
        }
        Array.Sort(tmp);
        for(int i = 0; i < m + n; i++)
        {
            nums1[i] = tmp[i];
        }
    }
}