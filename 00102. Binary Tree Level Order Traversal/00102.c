#define MAX_NODE_SIZE   2000

bool isEmpty(int qIndex, int qSize) {
    return qIndex == qSize;
}

void enqueue(struct TreeNode *queue[], int *qSize, struct TreeNode *newNode) {
    if (newNode != NULL) {
        queue[(*qSize)++] = newNode;
    }
}

void dequeueAll(struct TreeNode *queue[], int *qIndex, int *qSize, int **ret, int *returnSize, int **returnColumnSizes) {
    int i, valCount, oldSize = *qSize;
    static int vals[1024] = {};
    struct TreeNode node;
    
    for (i = *qIndex, valCount = 0; i < oldSize; ++i, ++valCount) {
        node = *(queue[i]);
        
        vals[valCount] = node.val;
        enqueue(queue, qSize, node.left);
        enqueue(queue, qSize, node.right);
    }
    *qIndex = oldSize;
    
    (*returnColumnSizes)[*returnSize] = valCount;
    ret[*returnSize] = (int *) malloc(sizeof(int) * valCount);
    memcpy(ret[(*returnSize)++], vals, sizeof(int) * valCount);
}

int ** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;

    int qSize = 0, qIndex = 0;
    struct TreeNode *queue[MAX_NODE_SIZE] = {};
    
    int **ret = (int *) malloc(sizeof(int *) * MAX_NODE_SIZE);
    memset(ret, 0, sizeof(int *) * MAX_NODE_SIZE);
    
    *returnColumnSizes = (int *) malloc(sizeof(int) * MAX_NODE_SIZE);
    
    enqueue(queue, &qSize, root);
    while (!isEmpty(qIndex, qSize)) {
        dequeueAll(queue, &qIndex, &qSize, ret, returnSize, returnColumnSizes);
    }

    return ret;
}
