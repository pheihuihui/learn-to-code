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
    public bool HasCycle(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return false;
        }
        ListNode start = head;
        for (int i = 0; ; i++)
        {
            start = start.next;
            if (start == null)
            {
                return false;
            }
            ListNode res = start;
            for(int a = 0; a <= i; a++)
            {
                start = start.next;
                {
                    if(start == null)
                    {
                        return false;
                    }
                }
                if(res == start)
                {
                    return true;
                }
            }
        }
    }
}