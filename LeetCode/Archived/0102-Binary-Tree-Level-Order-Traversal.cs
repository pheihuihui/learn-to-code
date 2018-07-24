public class Solution
{
    List<List<int>> res = new List<List<int>>();
    Dictionary<int, List<int>> dd = new Dictionary<int, List<int>>();
    public List<List<int>> LevelOrder(TreeNode root)
    {
        LLevelOrder(0, root);
        for(int i = 0; i < dd.Count; i++)
        {
            res.Add(dd[i]);
        }
        return res;
    }
    public void LLevelOrder(int level, TreeNode root)
    {
        if (root != null)
        {
            if (!dd.ContainsKey(level))
            {
                dd.Add(level, new List<int>());
            }
            dd[level].Add(root.val);
            LLevelOrder(level + 1, root.left);
            LLevelOrder(level + 1, root.right);
        }
    }
}