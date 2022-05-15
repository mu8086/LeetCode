void enQueue(struct TreeNode* queue[], int* size, struct TreeNode* node) {
    queue[(*size)++] = node;
}

int deQueueAll(struct TreeNode* queue[], int* index, int* size) {
    int sum = 0, sibling = *size - *index;
    struct TreeNode* node = NULL;
    
    for (int i=0; i<sibling; i++) {
        node = queue[(*index)++];
        sum += node->val;
        
        if (node->left != NULL) {
            enQueue(queue, size, node->left);
        }
        if (node->right != NULL) {
            enQueue(queue, size, node->right);
        }
    }
    
    return sum;
}

bool isEmptyQueue(struct TreeNode* queue[], int index) {
    return queue[index] == NULL;
}

int deepestLeavesSum(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    
    int sum = 0, index = 0, size = 1;
    struct TreeNode* queue[10001] = {root};

    while (!isEmptyQueue(queue, index)) {
        sum = deQueueAll(queue, &index, &size);
    }
    
    return sum;
}
