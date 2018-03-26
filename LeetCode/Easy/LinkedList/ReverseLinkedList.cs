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
    public ListNode ReverseList(ListNode head) 
    {
        if(head == null || head.next == null)
        {
            return head;
        }
        ListNode p = head;
        ListNode newhead = null;
        while (p != null)
        {
            ListNode tmp = p.next;
            p.next = newhead;
            newhead = p;
            p = tmp;
        }
        return newhead;
    }
}