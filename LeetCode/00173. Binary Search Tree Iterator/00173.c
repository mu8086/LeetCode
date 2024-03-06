struct MyListNode {
    struct TreeNode* node;
    struct MyListNode* next;
};

typedef struct {
    struct MyListNode* head;
    struct MyListNode* curr;
} BSTIterator;

void inorderTraversal(struct MyListNode** head, struct MyListNode** curr, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(head, curr, root->left);
    
    struct MyListNode* newNode = (struct MyListNode*) malloc(sizeof(struct MyListNode));
    newNode->node = root;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *curr = newNode;
    } else {
        (*curr)->next = newNode;
        *curr = newNode;
    }
    
    inorderTraversal(head, curr, root->right);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* ret = (BSTIterator*) malloc(sizeof(BSTIterator));
    ret->head = NULL, ret->curr = NULL;

    inorderTraversal(&(ret->head), &(ret->curr), root);
    
    ret->curr = ret->head;
    
    return ret;
}

int bSTIteratorNext(BSTIterator* obj) {
    int ret = obj->curr->node->val;
    obj->curr = obj->curr->next;
    return ret;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->curr != NULL;
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj != NULL) {
        for (struct MyListNode* walker = obj->head, *next; walker != NULL; walker = next) {
            next = walker->next;
            free(walker);
        }
        free(obj);
    }
}
