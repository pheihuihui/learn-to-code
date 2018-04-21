public class MinStack
{
    Dictionary<int, int> dc;
    public MinStack()
    {
        dc = new Dictionary<int, int>();
    }
    public void Push(int x)
    {
        dc.Add(dc.Count, x);
    }
    public void Pop()
    {
        if(dc.Count != 0)
        {
            dc.Remove(dc.Count - 1);
        }
        else
        {
            return;
        }
    }
    public int Top()
    {
        if(dc.Count != 0)
        {
            return dc[dc.Count - 1];
        }
        else
        {
            return Int32.MinValue;
        }
    }
    public int GetMin()
    {
        if(dc.Count == 0)
        {
            return Int32.MinValue;
        }
        else if(dc.Count == 1)
        {
            return dc[0];
        }
        else
        {
            int res = dc[0];
            for(int i = 1; i < dc.Count; i++)
            {   
                if(dc[i] < res)
                {
                    res = dc[i];
                }
            }
            return res;
        }
    }
}

//too slow