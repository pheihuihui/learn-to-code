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
    public ListNode RemoveNthFromEnd(ListNode head, int n) 
    {
        ListNode res = head;
        int length = 0;
        while(head != null)
        {
            head = head.next;
            length += 1;
        }
        head = res;
        for(int i = 0; i < length - n; i ++)
        {
            head = head.next;
        }
        
        head.val = head.next.val;
        head.next = head.next.next;
        return res;
    }
}