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
        if (head.next == null)
        {
            return null;
        }
        ListNode res = head;
        ListNode front = head;
        for (int i = 0; i < n; i++)
        {
            front = front.next;
        }
        if(front == null)
        {
            head = head.next;
            return head;
        }
        while (front.next != null)
        {
            head = head.next;
            front = front.next;
        }
        head.next = head.next.next;
        return res;
    }
}