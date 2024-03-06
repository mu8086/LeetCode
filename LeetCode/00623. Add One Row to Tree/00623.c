struct TreeNode * addOneRow(struct TreeNode *root, int val, int depth) {
    if (depth == 1) {
        struct TreeNode *newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        *newNode = (struct TreeNode){ .left = root, .right = NULL, .val = val };
        return newNode;
    } else if (depth == 2) {
        struct TreeNode *nodes = (struct TreeNode *) malloc(sizeof(struct TreeNode) * 2);
        *(nodes)    = (struct TreeNode){ .left = root->left,    .right = NULL,          .val = val          };
        *(nodes+1)  = (struct TreeNode){ .left = NULL,          .right = root->right,   .val = val          };
        *root       = (struct TreeNode){ .left = nodes,         .right = nodes+1,       .val = root->val    };
        return root;
    }

    if (root->left != NULL) {
        addOneRow(root->left, val, depth-1);
    }
    if (root->right != NULL) {
        addOneRow(root->right, val, depth-1);
    }

    return root;
}
