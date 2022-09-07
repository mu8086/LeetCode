class Solution {
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        } else {
            String ret = root.val + "";
            
            if (root.left != null || root.right != null) {
                ret += "(" + tree2str(root.left) + ")";

                if (root.right != null) {
                    ret += "(" + tree2str(root.right) + ")";
                }
            }
            
            return ret;
        }
    }
}
