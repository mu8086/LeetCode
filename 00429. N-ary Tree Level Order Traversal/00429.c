void enQueue(struct Node* queue[], int* size_q, struct Node* node) {
    queue[(*size_q)++] = node;
}

void deQueueAll(struct Node* queue[], int* index_q, int* size_q, int** ret, int* returnSize, int* returnColumnSizes) {
    int i, j, siblings = *size_q - *index_q;
    struct Node* node;

    returnColumnSizes[*returnSize] = siblings;
    ret[*returnSize] = (int*) malloc(sizeof(int) * siblings);
    
    for (i=0; i<siblings; i++) {
        node = queue[(*index_q)++];
        ret[*returnSize][i] = node->val;
        
        for (j=0; j<node->numChildren; j++) {
            enQueue(queue, size_q, (node->children)[j]);
        }
    }
    
    (*returnSize)++;
}

bool isEmptyQueue(struct Node* queue[], int index_q) {
    return queue[index_q] == NULL;
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int max_height = 1000;
    int** ret = (int**) malloc(sizeof(int*) * max_height);
    memset(ret, 0, sizeof(int*) * max_height);
    
    *returnColumnSizes = (int*) malloc(sizeof(int) * max_height);
    memset(*returnColumnSizes, 0, sizeof(int) * max_height);
        
    int index_q = 0, size_q = 1;
    struct Node* queue[10000] = {root};
        
    while (!isEmptyQueue(queue, index_q)) {
        deQueueAll(queue, &index_q, &size_q, ret, returnSize, *returnColumnSizes);
    }
    
    return ret;
}
