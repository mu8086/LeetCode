// https://leetcode.com/problems/leaf-similar-trees

#define MAX_SIZE 200

void getLeaf(struct TreeNode *root, int leaf[], int *size) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        leaf[*size] = root->val;
        ++(*size);
    } else {
        getLeaf(root->left, leaf, size);
        getLeaf(root->right, leaf, size);
    }
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
    int size1 = 0, size2 = 0, leaf1[MAX_SIZE] = {}, leaf2[MAX_SIZE] = {};

    getLeaf(root1, leaf1, &size1);
    getLeaf(root2, leaf2, &size2);

    return size1 == size2 && !memcmp(leaf1, leaf2, sizeof(int) * MAX_SIZE);
}
