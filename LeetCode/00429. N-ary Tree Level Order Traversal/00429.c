#define MAX_LEVEL_SIZE  1000
#define MAX_NODE_SIZE   10000

bool isEmptyQueue(int size, int index) {
    return size-1 == index;
}

void enQueue(struct Node *queue[], int *qSize, struct Node *node) {
    queue[(*qSize)++] = node;
}

void deQueueAll(struct Node *queue[], int *qSize, int *qIndex, int *levelTable[], int levelSize[], int level) {
    int i, j, jSize, k, oldSize = *qSize;

    levelSize[level] = oldSize - ((*qIndex)+1);
    int *tmp = levelTable[level] = (int *) malloc(sizeof(int) * levelSize[level]);

    for (i = (*qIndex)+1, k = 0; i < oldSize; ++i, ++k) {
        tmp[k] = queue[i]->val;

        for (j = 0, jSize = queue[i]->numChildren; j < jSize; ++j) {
            enQueue(queue, qSize, queue[i]->children[j]);
        }
    }

    *qIndex = oldSize-1;
}

int ** levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (root == NULL) {
        return NULL;
    }

    int *levelTable[MAX_LEVEL_SIZE] = {};
    int levelSize[MAX_LEVEL_SIZE] = {};
    int i, **ans = NULL;

    int qSize = 0, qIndex = -1;
    struct Node *queue[MAX_NODE_SIZE] = {};

    enQueue(queue, &qSize, root);

    while (!isEmptyQueue(qSize, qIndex)) {
        deQueueAll(queue, &qSize, &qIndex, levelTable, levelSize, *returnSize);
        ++(*returnSize);
    }

    if (*returnSize != 0) {
        ans = (int **) malloc(sizeof(int *) * *returnSize);
        memcpy(ans, levelTable, sizeof(int *) * *returnSize);

        *returnColumnSizes = (int *) malloc(sizeof(int) * *returnSize);
        for (i = (*returnSize)-1; i >= 0; --i) {
            (*returnColumnSizes)[i] = levelSize[i];
        }
    }

    return ans;
}
