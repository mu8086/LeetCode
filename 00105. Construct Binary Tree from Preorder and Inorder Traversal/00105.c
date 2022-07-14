#define INVALID -1

int findRootValIndexInInorder(int val, int *inorder, int inBegin, int inEnd) {
    for (int i = inBegin; i <= inEnd; ++i) {
        if (inorder[i] == val) {
            return i;
        }
    }
    
    return INVALID;
}

struct TreeNode * builder(int *preorder, int preBegin, int preEnd, int *inorder, int inBegin, int inEnd) {
    static int size = sizeof(struct TreeNode);
    struct TreeNode *root = (struct TreeNode *) malloc(size);
    root->val = preorder[preBegin];
    root->left = root->right = NULL;
    
    if (preBegin != preEnd) {
        int rootInInorderIndex = findRootValIndexInInorder(root->val, inorder, inBegin, inEnd);
        int lSize = rootInInorderIndex - inBegin;
        
        // left
        if (rootInInorderIndex != inBegin) {
            root->left = builder(preorder, preBegin+1, preBegin+lSize, inorder, inBegin, rootInInorderIndex-1);
        }
        
        // right
        if (rootInInorderIndex != inEnd) {
            root->right = builder(preorder, preBegin+lSize+1, preEnd, inorder, rootInInorderIndex+1, inEnd);
        }
    }
    
    return root;
}

struct TreeNode * buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    return builder(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
}
