#define MAX_NODE    10000

void traversal(struct TreeNode *root, double table[][2], int level, int *maxLevel) {
    if (root != NULL) {
        if (*maxLevel < level) {
            *maxLevel = level;
        }
        
        double newCount = table[level][0] + 1;

        table[level][1] = table[level][1] / newCount * table[level][0] + (double)(root->val) / newCount;
        table[level][0] = newCount;
        
        traversal(root->left,  table, level+1, maxLevel);
        traversal(root->right, table, level+1, maxLevel);
    }
}

double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    int i, maxLevel = 0;
    double table[MAX_NODE][2] = {};    // [][0]: same level node count, [][1]: same level node sum
    
    traversal(root, table, 0, &maxLevel);
    
    *returnSize = maxLevel+1;
    double *ans = (double *) malloc(sizeof(double) * (maxLevel+1));
    
    for (i = 0; i <= maxLevel; ++i) {
        ans[i] = table[i][1];
    }
    
    return ans;
}
