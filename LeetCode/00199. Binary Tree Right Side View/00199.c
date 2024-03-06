#define MAX_NODE_DEPTH  100
#define INIT_VAL        101

void traversal(struct TreeNode *root, int depth, char tmp[]) {
    if (root == NULL) {
        return;
    }
    
    tmp[depth] = root->val;
    traversal(root->left,  depth+1, tmp);
    traversal(root->right, depth+1, tmp);
}

int * rightSideView(struct TreeNode *root, int *returnSize) {
    static int ret[MAX_NODE_DEPTH] = {};
    char tmp[MAX_NODE_DEPTH] = {};
    memset(ret, 0, sizeof(int) * MAX_NODE_DEPTH);
    memset(tmp, INIT_VAL, sizeof(char) * MAX_NODE_DEPTH);
    
    traversal(root, 0, tmp);

    int i;
    
    for (i = 0; i < MAX_NODE_DEPTH && tmp[i] != INIT_VAL; ++i) {
        ret[i] = (int)(tmp[i]);
    }
    *returnSize = i;
    
    return ret;
}
