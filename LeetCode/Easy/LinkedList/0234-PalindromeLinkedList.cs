public class Solution
{
    public bool IsPalindrome(ListNode head)
    {
        if(head == null)
        {
            return true;
        }
        else if(head.next == null)
        {
            return true;
        }
        List<int> ls = new List<int>();
        while(head != null)
        {
            ls.Add(head.val);
            head = head.next;
        }
        int[] nums = ls.ToArray();
        int a = 0;
        int b = nums.Length - 1;
        while(a <= b)
        {
            if(nums[a] != nums[b])
            {
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
}