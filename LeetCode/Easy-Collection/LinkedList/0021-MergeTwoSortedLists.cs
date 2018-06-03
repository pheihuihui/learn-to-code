public class ListNode 
{
    public int val;
    public ListNode next;
    public ListNode(int x) 
    { 
        val = x; 
    }
}

public class Solution
{
    public ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        if (l1 == null)
        {
            return l2;
        }
        if (l2 == null)
        {
            return l1;
        }
        ListNode head = new ListNode(0);
        ListNode res = head;
        while(l1 != null || l2 != null)
        {
            int tmp;
            if (l1 == null)
            {
                tmp = l2.val;
                l2 = l2.next;
            }
            else if (l2 == null)
            {
                tmp = l1.val;
                l1 = l1.next;
            }
            else
            {
                if (l1.val <= l2.val)
                {
                    tmp = l1.val;
                    l1 = l1.next;
                }
                else
                {
                    tmp = l2.val;
                    l2 = l2.next;
                }
            }
            head.next = new ListNode(tmp);
            head = head.next;
        }
        return res.next;
    }
}