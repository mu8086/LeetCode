void enQueue(struct Node* queue[], int* size_q, struct Node* node) {
    queue[(*size_q)++] = node;
}

void deQueueAll(struct Node* queue[], int* index_q, int* size_q) {
    int old_size = *size_q;
    
    for (struct Node* node, *lastNode=NULL; *index_q<old_size; (*index_q)++) {
        node = queue[*index_q];
        if (lastNode) {
            lastNode->next = node;
        }
        
        if (node->left) {
            enQueue(queue, size_q, node->left);
        }
        if (node->right) {
            enQueue(queue, size_q, node->right);
        }
        
        lastNode = node;
    }
    
    return;
}

bool isEmptyQueue(struct Node* queue[], int index_q) {
    return queue[index_q] == NULL;
}

struct Node* connect(struct Node* root) {
    if (root) {
        int index_q = 0, size_q = 1;
        struct Node* queue[6000] = {root};
        
        while (!isEmptyQueue(queue, index_q)) {
            deQueueAll(queue, &index_q, &size_q);
        }
    }
    
    return root;
}
