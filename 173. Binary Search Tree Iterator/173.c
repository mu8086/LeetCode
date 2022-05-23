#define MAX_NODE 100000

typedef struct {
    int size;
    struct TreeNode** stack;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* ret = (struct BSTIterator*) malloc(sizeof(BSTIterator));
    
    ret->size = 0;
    ret->stack = (struct TreeNode**) malloc(sizeof(struct TreeNode*) * MAX_NODE);
    
    if (root != NULL) {
        ret->stack[(ret->size)++] = root;

        for (root = root->left; root != NULL; root = root->left) {
            ret->stack[(ret->size)++] = root;
        }
    }
    
    return ret;
}

int bSTIteratorNext(BSTIterator* obj) {
    int ret = obj->stack[(obj->size)-1]->val;
    
    if (obj->stack[(obj->size)-1]->right != NULL) {
        for (struct TreeNode* root = obj->stack[(obj->size)-1]->right; root != NULL; root = root->left) {
            obj->stack[(obj->size)++] = root;
        }
    } else {
        int height;

        for (height=(obj->size)-1; height>=1; height--) {
            if (obj->stack[height] != obj->stack[height-1]->right) {
                break;
            }
        }
        obj->size = height;
    }
    
    return ret;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->size > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj != NULL) {
        free(obj->stack);
        free(obj);
    }
}
