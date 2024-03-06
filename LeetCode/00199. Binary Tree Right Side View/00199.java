class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
  
        traversal(result, root, 0);
        
        return result;
    }
    
    public void traversal(List<Integer> result, TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        
        if (result.size() == depth) {
            result.add(root.val);
        }
        
        traversal(result, root.right, depth+1);
        traversal(result, root.left,  depth+1);
    }
}
