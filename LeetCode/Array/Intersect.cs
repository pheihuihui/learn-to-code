public class Solution
{
    public int[] Intersect(int[] nums1, int[] nums2)
    {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        for(int i = 0; i <= len1 - 1; i++)
        {
            for(int j = 0; j <= len2 - 1; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    int temp = nums2[len2 - 1];
                    nums2[len2 - 1] = nums2[j];
                    nums2[j] = temp;
                    len2 -= 1;
                    break;
                }
            }
            int tmp = nums1[len1 - 1];
            nums1[len1 - 1] = nums1[i];
            nums1[i] = tmp;
            len1 -= 1;
        }
        int[] res = new int[nums2.Length - len2];
        for(int s = 0; s <= nums2.Length - len2 - 1; s++)
        {
            res[s] = nums2[len2 + s];
        }
        return res;
    }
}
