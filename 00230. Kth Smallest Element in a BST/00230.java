class Solution {
    public void inorder(TreeNode root, int[] helper, int k) {
        if (root != null) {
            inorder(root.left,  helper, k);
            if (helper[0]++ == k) {
                helper[1] = root.val;
            }
            inorder(root.right, helper, k);
        }
    }
    
    public int kthSmallest(TreeNode root, int k) {
        int[] helper = {1, 0};  // [0]: counter, [1]: ans
        inorder(root, helper, k);
        return helper[1];
    }
}
