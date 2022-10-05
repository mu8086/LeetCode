struct TreeNode * addOneRow(struct TreeNode *root, int val, int depth) {
    if (depth == 1) {
        struct TreeNode *newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        *newNode = (struct TreeNode){ .left = root, .right = NULL, .val = val };
        return newNode;
    } else if (root == NULL) {
        return NULL;
    }

    struct TreeNode *l = addOneRow(root->left,  val, depth-1);
    struct TreeNode *r = addOneRow(root->right, val, depth-1);

    // if l is a newNode, connect root->left to it
    if (l != root->left) {
        root->left = l;
    }

    // if r is a newNode, connect root->right to it
    if (r != root->right) {
        // for handle original depth 1 case (i.e. insert newNode as root's parent),
        // we set the root as default newNode->left
        // but in the r case, we should swap the newNode->left & newNode->right
        r->left = NULL;
        r->right = root->right;
        root->right = r;
    }

    return root;
}
