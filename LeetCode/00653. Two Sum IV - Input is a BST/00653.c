#define MAX_SIZE    20001

void traversal(struct TreeNode *root, int k, int map[], int *count) {
    if (root != NULL && *count == 0) {
        int val = root->val;

        if (k - val >= -10000 && k - val <= 10000) {
            if (map[k - val] != 0) {
                ++(*count);
                return;
            }

            ++map[val];
        }

        traversal(root->left,  k, map, count);
        traversal(root->right, k, map, count);
    }
}

bool findTarget(struct TreeNode *root, int k) {
    if (k < -20000 || k > 20000) {
        return false;
    }

    int map[MAX_SIZE] = {}, offset = 10000, count = 0;

    traversal(root, k, map + offset, &count);

    return count > 0;
}
